#include <stdio.h>

int main()
{
    float a, b, x;

    printf("Enter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    printf("Enter x: ");
    scanf("%f", &x);

    float sum = a + b;
    float result;
    
    if (x == 0 && sum <= x)
    {
        printf("x is zero!\n");
        return 0;
    }
    if (sum == 0 && sum > x)
    {
        printf("sum is zero!\n");
        return 0;
    }

    if (sum < x)
        result = sum / x;
    else if (sum > x)
        result = x / sum;
    else
        result = b / x;

    printf("Result: %.3f\n", result);
    return 0;
}
