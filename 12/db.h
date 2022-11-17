#ifndef DB_H
#define DB_H

#include "student.h"
#include <stdio.h>

int add_student(struct student** db, int db_size);
int remove_student(struct student** db, int db_size, int index);
int edit_student(struct student** db, int db_size, int index);

int read_from_file(struct student** db, FILE file);
void write_to_file(struct student** db, int db_size, FILE file);

#endif