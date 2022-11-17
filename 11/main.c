#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <termios.h>
#include <unistd.h>

struct student
{
    char* name;
    char* surname;
    int group;
    int* marks;
};

float average(int a[3])
{
    return (a[0] + a[1] + a[2]) / 3.0;
}

void register_student(struct student* item)
{
    char* name = malloc(200);
    char* surname = malloc(200);
    int group_field, group_class;
    int* marks = malloc(3 * sizeof(int));

    printf("Фамилия: ");
    scanf("%s", name);
    printf("Имя: ");
    scanf("%s", surname);
    printf("Группа: ");
    scanf("%d-%d", &group_field, &group_class);
    printf("3 оценки за экзамены: ");
    scanf("%d %d %d", &marks[0], &marks[1], &marks[2]);

    item->name = name;
    item->surname = surname;
    item->group = group_field * 100 + group_class;
    item->marks = marks;
}

int add_student(struct student** db, int db_size)
{
    *db = realloc(*db, (db_size + 1) * sizeof(struct student));
    if (NULL == db)
    {
        printf("Не удалось выделить память!\n");
        exit(EXIT_FAILURE);
    }

    struct student* new_item = &(*db)[db_size++];
    register_student(new_item);
    printf("Студент добавлен.\n");
    return db_size;
}

int print_student(struct student item)
{
    //       фам   имя   группа     оценки      средн.
    printf("%-30s|%-20s|%03i-%02i| %1i %1i %1i |%1.2f",
    item.name, item.surname,
    item.group / 100, item.group % 100,
    item.marks[0], item.marks[1], item.marks[2],
    average(item.marks));
}

void print_all(struct student db[], int db_size)
{
    printf(" ID | Фамилия                      | Имя                |Группа| Оценки|Ср. балл\n");
    for (int i = 0; i < db_size; i++)
    {
        printf("%4i|", i);
        print_student(db[i]);
        printf("\n");
    }
}

void print_excellent(struct student db[], int db_size)
{
    printf(" ID | Фамилия                      | Имя                |Группа| Оценки|Ср. балл\n");
    for (int i = 0; i < db_size; i++)
    {
        if (average(db[i].marks) - 4.50 >= -0.005)
        {
            printf("%4i ", i);
            print_student(db[i]);
            printf("\n");
        }
    }
}

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


int main()
{
    struct student* database = NULL;
    int db_size = 0;

    while (1)
    {
        printf("[1] - добавить, [2] - вывести всё, [3] - вывести всех со средним баллом >= 4.5, [q] - выход >");
        char answer;
        answer = mygetch();
        printf("\n");

        switch (answer)
        {
            case '1':
                db_size = add_student(&database, db_size);
                break;
            case '2':
                print_all(database, db_size);
                break;
            case '3':
                print_excellent(database, db_size);
                break;
            case 'q':
                return 0;
                break;
            case '\n':
                break;
            default:
                printf("Неизвестная команда\n");
                break;
        }

        __fpurge(stdin);
    }
}