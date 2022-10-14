#include <stdio.h>
#include <math.h>

typedef unsigned char bool;

bool is_input_valid(double x);

int main()
{
    double x;
    printf("Enter x: ");
    scanf("%lf", &x);

    if (is_input_valid(x))
    {
        double y = sqrt(sin(2 * x)) + sqrt(sin(3 * x));
        double z = sqrt(sqrt( log(tan( y - (M_PI / 8) )) ));

        printf("  y(x)  = %8lf\nz(y(x)) = %8lf\n", y, z);
    }
    else 
    {
        printf("Введённый x вне области определения!\n");
    }

    return 0;
}

bool is_input_valid(double x)
{
    int n = (int)(x / M_PI) / 2;
    double remainder = x - (M_PI * 2 * n);
    return 0.14352 < remainder && remainder < 1.02834;
}
