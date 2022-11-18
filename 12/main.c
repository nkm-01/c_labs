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
{}

int main()
{
    struct student* database = NULL;
    int db_size = 0;
    char command[255];

    char db_file[] = "students.db";

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
            if (id == 0 || command[6] == '\0' || !isspace(command[6]))
                printf("usage: delete <id>");
            else
                remove_student(&database, db_size, id);
        }
        else if (strcmp(command, "modify") == 0)
        {
            int id = atoi(command + 7);
            if (id == 0 || command[6] == '\0' || !isspace(command[6]))
                printf("usage: modify <id>");
            else
                edit_student(database, id);
        }
        else if (strcmp(command, "save") == 0)
        {
            write_to_file(database, db_size, db_file);
        }
        else if (strcmp(command, "load") == 0)
        {
            read_from_file(&database, db_size, db_file);
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