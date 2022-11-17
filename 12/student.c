#include <stdio.h>
#include <stdlib.h>

#include "student.h"

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