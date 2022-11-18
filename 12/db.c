#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "db.h"

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

int remove_student(struct student** db, int db_size, int index)
{
    if (db_size <= 0)
        return 0;

    db_size--;
    struct student* new_loc = malloc( db_size * sizeof(struct student) );
    size_t glue_offset = (index - 1)*sizeof(struct student);
    
    memcpy(new_loc, *db, index + glue_offset);
    memcpy(new_loc + glue_offset, *db, db_size * sizeof(struct student) - glue_offset);
}

void edit_student(struct student* db, int index)
{
    register_student(&db[index]);
}

int read_from_file(struct student** db, int db_size, const char* filename)
{
    if (*db != NULL)
    {
        printf("DB is not empty; replacing from file\n");
        free_db(db, db_size);
    }

    FILE* file = fopen(filename, "r");
    if (NULL == file)
    {
        *db = NULL;
        printf("file %s not found.\n", filename);
        return 0;
    }

    db_size = 0;
    fscanf(file, "%d", &db_size);
    *db = malloc(db_size * sizeof(struct student));
    for (int i = 0; i < db_size; i++)
    {
        struct student* s = &(*db)[i];
        
        char* name = malloc(200);
        char* surname = malloc(200);
        fscanf(file, "%s %s %d %d %d %d", name, surname, &s->group,
            &s->marks[0], &s->marks[1], &s->marks[2]);
        
        s->name = name;
        s->surname = surname;
    }

    return db_size;
}

void write_to_file(struct student* db, int db_size, const char* filename)
{
    FILE* file = fopen(filename, "w");
    if (NULL == file)
    {
        printf("Cannot open or create file %s. Data is not saved!", filename);
        return;
    }

    fprintf(file, "%d\n", db_size);
    for (int i = 0; i < db_size; i++)
    {
        fprintf(file, "%s %s\n%d\n%d %d %d\n", db[i].name, db[i].surname,
        db[i].group, db[i].marks[0], db[i].marks[1], db[i].marks[2]);
    }
}

void free_db(struct student** db, int db_size)
{
    for (int i = 0; i < db_size; i++)
    {
        free((*db[i]).name);
        free((*db[i]).surname);
    }

    free(*db);
    *db = NULL;
}