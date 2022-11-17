#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    fflush(stdin);
}

int main()
{
    struct student* database = NULL;
    int db_size = 0;
    char command[255];
    printf(">");

    safe_prompt(command, 255);

    while (1)
    {
        

        if (strcmp(command, "add") == 0)
            add_student();
        else if (strcmp(command, "print") == 0)
        {
            safe_prompt(command, 255);

            if ()
        }
        else if (strcmp(command, "delete") == 0)
        else if (strcmp(command, "modify") == 0)
        else if (strcmp(command, "save") == 0)
        else if (strcmp(command, "load") == 0)
        else if (strcmp(command, "quit") == 0)
        else if (strcmp(command, "help") == 0)
        else
        {

        }
    }
}