#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fill_random(int n, int a[])
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand () % 101 - 50;
}

int find_same_element(int from, int a[], int array_size)
{
    for (int i = from + 1; i < array_size; i++)
        if (a[from] == a[i])
            return i;
    
    return -1;
}

int find_sum(int from, int to, int a[])
{
    int sum = 0;
    for (int i = from; i <= to; i++)
        sum += a[i];
    
    return sum;
}

int find_product(int from, int to, int a[])
{
    int product = 1;
    for (int i = from; i <= to; i++)
        product *= a[i];
    
    return product;
}

int print_array()
{

}

int main()
{
    srand(time(NULL));

    int array_size;
    printf("Введите размер массива: ");
    scanf("%d", &array_size);
    int a[array_size];
    fill_random(array_size, a);

    printf("Массив до:\n");
    print_array(array_size, a);

    for (int i = 0; i < array_size; i++)
    {
        int same_number = find_same_element(i, a, array_size);
        if (same_number != -1)
        {
            int sum = find_sum(i + 1, same_number - 1, a);
            int product = find_product(i + 1, same_number - 1, a);

            a[i] = sum;
            a[same_number] = product;
            break;
        }
    }

    printf("Массив после:\n");
    print_array(array_size, a);
}