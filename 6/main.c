#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fill_random(int n, int a[])
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand () % 20 - 10;
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

int print_array(int size, int a[])
{
    printf("       "); // 7 пробелов
    for (int i = 0; i <= 9; i++)
        printf("%6d ", i);
    printf("\n");

    for (int l = 0; l <= size/10; l++)
    {
        if (l * 10 >= size)
            break;
        printf("%6d ", l);
        for (int i = l * 10; i < size && i < (l + 1) * 10; i++)
            printf("%6d ", a[i]);
        printf("\n");
    }
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

    int sum, product, begin_number, same_number = -1;
    for (int i = 0; i < array_size; i++)
    {
        same_number = find_same_element(i, a, array_size);
        if (same_number != -1)
        {
            sum = find_sum(i + 1, same_number - 1, a);
            product = find_product(i + 1, same_number - 1, a);

            a[i] = sum;
            a[same_number] = product;
            begin_number = i;
            break;
        }
    }

    printf("Массив после:\n");
    print_array(array_size, a);

    if (same_number != -1)
    {
        printf("Одинаковые элементы № %d и %d.\nСумма элементов между ними: %d, произведение: %d\n",
            begin_number, same_number, sum, product);
    }
    else
        printf("Одинаковые элементы не найдены.\n");

    return 0;
}