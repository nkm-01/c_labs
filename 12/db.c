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