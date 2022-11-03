#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void transpose(int n, int m, int a[n][m], int t[m][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            t[j][i] = a[i][j];
    }
}

void multiply(int n, int m, int a[n][m], int b[m][n], int p[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = 0;
                for (int k = 0; k < m; k++)
                    sum += a[i][k] * b[k][j];
                p[i][j] = sum;
            }
        }
    }
}

void print_matrix(int n, int m, int a[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%6d ", a[i][j]);
        printf("\n");
    }
}

void fill_random(int n, int m, int a[n][m])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = rand() % 30 - 15;
}

int main()
{
    int n, m;
    printf("Размер матрицы (WxH): ");
    scanf("%dx%d", &n, &m);

    srand(time(NULL));

    int a[n][m];
    int t[m][n];
    int product[n][n];

    fill_random(n, m, a);
    printf("Матрица A:\n");
    print_matrix(n, m, a);

    transpose(n, m, a, t);
    printf("Транспонированая матрица T:\n");
    print_matrix(m, n, t);

    multiply(n, m, a, t, product);
    printf("Произведение A×T:\n");
    print_matrix(n, n, product);

    return 0;
}