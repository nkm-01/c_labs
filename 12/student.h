#ifndef STUDENT_H
#define STUDENT_H

struct student
{
    char* name;
    char* surname;
    int group;
    int* marks;
};

float average(int a[3]);
void register_student(struct student* item);

#endif