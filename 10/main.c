#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void* safe_alloc(size_t size, const char* alloc_for)
{
    int* mem = malloc(size);
    if (NULL == mem)
    {
        printf("Не могу выделить память! Нужно %d КиБ.\n", size / 1024);
        exit(EXIT_FAILURE);
    }
    else
        printf("Успешно выделено %d байт на %s.\n", size, alloc_for);
    
    return mem;
}

int* transpose(int n, int m, int* a)
{
    int* t = safe_alloc(m * n * sizeof(int), "транспонированную матрицу");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            t[j * n + i] = a[i * m + j];
    }

    return t;
}

int* multiply(int n, int m, int* a, int* b)
{
    int* p = safe_alloc(n * n * sizeof(int), "на матрицу-произведение");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int k = 0; k < m; k++)
                sum += a[i * m + k] * b[k * n + j];
            p[i * n + j] = sum;
        }
    }

    return p;
}

void print_matrix(int n, int m, int* a)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%6d ", a[i * m + j]);
        printf("\n");
    }
}

void fill_random(int n, int m, int* a)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i * m + j] = rand() % 30 - 15;
}

int main()
{
    int n, m;
    printf("Размер матрицы (WxH): ");
    scanf("%dx%d", &m, &n);

    srand(time(NULL));

    int* a = safe_alloc(n * m * sizeof(int), "матрицу");

    fill_random(n, m, a);
    printf("Матрица A:\n");
    print_matrix(n, m, a);

    int* t = transpose(n, m, a);
    printf("Транспонированая матрица T:\n");
    print_matrix(m, n, t);

    int* product = multiply(n, m, a, t);
    printf("Произведение A×T:\n");
    print_matrix(n, n, product);

    free(a);
    free(t);
    free(product);

    return 0;
}
