#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
typedef char bool;

int mygetch()
{
    struct termios oldt, newt;
    int c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

bool sym_valid(char c)
{
    return isdigit(c) || c == '-' || c == 'e' || c == '.';
}

int main()
{
    bool is_ctrl = FALSE, is_first_ctrl_entered = FALSE;
    char first_ctrl, second_ctrl;
    int points_count = 0;
    int exponent_count = 0;
    bool all_syms_valid = TRUE;
    bool begin_enter_number = FALSE;

    while (1)
    {
        char c = mygetch();

        if (isprint(c) && !is_ctrl)
        {
            printf("%c", c);

            if (isspace(c))
                continue;

            if (!sym_valid(c))
                all_syms_valid = FALSE;
            
            if (c == '.')
            {
                points_count++;
                if (exponent_count > 0)
                    all_syms_valid = FALSE;
            }
            
            if (isdigit(c) || c == '.')
                begin_enter_number = TRUE;
            
            if (c == '-')
            {
                if (begin_enter_number)
                    all_syms_valid = FALSE;
                else
                    begin_enter_number = TRUE;
            }
            
            if (c == 'e')
            {
                exponent_count++;
                begin_enter_number = FALSE;
            }
        }
        else // !isprint(c) || is_ctrl
        {
            if (c == 0x1b) // escape
            {
                is_ctrl = TRUE;
                continue;
            }
            
            if (is_ctrl && !is_first_ctrl_entered)
            {
                first_ctrl = c;
                is_first_ctrl_entered = TRUE;
            }
            else if (is_ctrl) // second entered
            {
                is_ctrl = FALSE;
                is_first_ctrl_entered = FALSE;
                second_ctrl = c;

                if (first_ctrl == '[' && second_ctrl == 'F')
                    break; //while loop
            }
        }
    }

    if (all_syms_valid && points_count <= 1 && exponent_count <= 1 && begin_enter_number == TRUE)
        printf ("\nВведено вещественное число.\n");
    else
        printf ("\nВведённые символы — не число.\n");
}