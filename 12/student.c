#include <stdio.h>
#include <stdio_ext.h>
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
    int group_field = 0, group_class = 0;
    int marks[3];

    printf("Surname: ");
    scanf("%s", name);
    printf("Name: ");
    scanf("%s", surname);
    printf("Group (xxx-xx): ");
    scanf("%d-%d", &group_field, &group_class);
    printf("3 exam marks: ");
    scanf("%d %d %d", &marks[0], &marks[1], &marks[2]);

    item->name = name;
    item->surname = surname;
    item->group = group_field * 100 + group_class;

    for (int i = 0; i < 3; i++)
        item->marks[i] = marks[i];

    __fpurge(stdin);
}

void free_student(struct student* student)
{
    free(student->name);
    free(student->surname);
    student->name = NULL;
    student->surname = NULL;
}