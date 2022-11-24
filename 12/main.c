#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <stdio_ext.h>

#include "student.h"
#include "print.h"
#include "db.h"

int mygetch()
{
    struct termios oldt, newt;
    int c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

void safe_prompt(char* buff, int size)
{
    fgets(buff, size, stdin);
    buff[size - 1] = '\0';
    for (int i = 0; i < size; i++)
        if (buff[i] == '\n')
        {
            buff[i] = '\0';
            break;
        }

    __fpurge(stdin);
}

void print_help()
{
    printf("list of commands:\n");
    printf("add -- add a new student to DB\n");
    printf("print all -- print all students in DB\n");
    printf("print excellent -- print all students with average mark >= 4.5\n");
    printf("delete <id> -- delete a student with ID <id>\n");
    printf("modify <id> -- edit data about student with ID <id>\n");
    printf("save -- save DB to file students.db\n");
    printf("load -- load DB from file students.db\n");
    printf("quit -- save DB to file and exit\n");
    printf("help -- print this text\n");
}

int test_id(int id, int db_size)
{
    if (id <= 0 || id > db_size)
    {
        printf("Введён неверный ID\n");
        return 0;
    }
    return 1;
}

int main()
{
    struct student* database = NULL;
    int db_size = 0;
    char command[255];

    char db_file[] = "students.db";

    db_size = read_from_file(&database, db_size, db_file);

    while (1)
    {
        printf(">");
        safe_prompt(command, 255);

        if (strcmp(command, "add") == 0)
            db_size = add_student(&database, db_size);
        else if (strncmp(command, "print", 5) == 0)
        {
            if (strcmp(command + 6, "all") == 0)
                print_all(database, db_size);
            else if (strcmp(command + 6, "excellent") == 0)
                print_excellent(database, db_size);
            else
                printf("usage: print < all | excellent >\n");
        }
        else if (strncmp(command, "delete", 6) == 0)
        {
            int id = atoi(command + 7);
            if (!test_id(id, db_size) || command[6] == '\0' || !isspace(command[6]))
                printf("usage: delete <id>\n");
            else
                db_size = remove_student(&database, db_size, id - 1);
        }
        else if (strncmp(command, "modify", 6) == 0)
        {
            int id = atoi(command + 7);
            if (!test_id(id, db_size) || command[6] == '\0' || !isspace(command[6]))
                printf("usage: modify <id>\n");
            else
                edit_student(database, id - 1);
        }
        else if (strcmp(command, "save") == 0)
        {
            write_to_file(database, db_size, db_file);
        }
        else if (strcmp(command, "load") == 0)
        {
            db_size = read_from_file(&database, db_size, db_file);
        }
        else if (strcmp(command, "quit") == 0)
        {
            write_to_file(database, db_size, db_file);
            break;
        }
        else if (strcmp(command, "help") == 0)
            print_help();
        else
        {
            printf("Unknown verb. Type 'help' to list commands.\n");
        }
    }
}
