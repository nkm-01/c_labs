#include <stdio.h>

#include "student.h"
#include "print.h"

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