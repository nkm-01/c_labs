#ifndef DB_H
#define DB_H

#include "student.h"
#include <stdio.h>

int add_student(struct student** db, int db_size);
int remove_student(struct student** db, int db_size, int index);
void edit_student(struct student* db, int index);

int read_from_file(struct student** db, int db_size, const char* filename);
void write_to_file(struct student* db, int db_size, const char* filename);

void free_db(struct student** db, int db_size);

#endif