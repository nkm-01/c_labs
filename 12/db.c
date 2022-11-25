#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "db.h"

int add_student(struct student** db, int db_size)
{
    *db = realloc(*db, (db_size + 1) * sizeof(struct student));
    if (NULL == db)
    {
        printf("Can't allocate memory!\nStudent is NOT added!");
        return db_size;
    }

    struct student* new_item = &(*db)[db_size++];
    register_student(new_item);
    printf("Student is added.\n");
    return db_size;
}

int remove_student(struct student** db, int db_size, int index)
{
    if (db_size <= 0)
        return 0;

    free_student(&(*db)[index]);

    db_size--;
    struct student* new_loc = malloc( db_size * sizeof(struct student) );
    size_t glue_offset = index * sizeof(struct student);

    memcpy(new_loc, *db, glue_offset);
    if (index + 1 <= db_size)
        memcpy(new_loc + index, *db + index + 1, db_size * sizeof(struct student) - glue_offset);

    *db = new_loc;
    return db_size;
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

    printf("DB loaded from file.\n");
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
    fclose(file);
}

void free_db(struct student** db, int db_size)
{
    for (int i = 0; i < db_size; i++)
        free_student(db[i]);

    free(*db);
    *db = NULL;
}
