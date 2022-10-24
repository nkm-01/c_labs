#include <stdio.h>

long cycle(int base, int pow)
{
    long result = 1;
    for (int i = 0; i < pow; i++)
        result *= base;
    
    return result;
}

long recurse(int base, int pow)
{
    if (pow == 1)
        return base;
    
    return recurse(base, pow - 1) * base;
}

int main()
{
    int base, pow;

    printf("Основание степени  >");
    scanf("%d", &base);
    printf("Показатель степени >");
    scanf("%d", &pow);

    printf("Цикл: %13ld\n", cycle(base, pow));
    printf("Рекурсия: %9ld\n", recurse(base, pow));

    return 0;
}