// pi/4 < y - pi/8 < pi/2
// (3/8)pi < y < (5/8)pi
// (3/8)pi < sqrt(sin2x) + sqrt(sin3x) < (5/8)pi;  0n < x < (pi/2)n;
//  
// (9/256)pi^2 < sin2x < (25/256)pi^2
// x = (pi*n + 0.1771736449; pi*n + 0.6505062889)
// x = (pi*n + 0.9202900379; pi*n + 1.393622682)

#define PI 3.141592653589793238462643383279l // нет в стандарте; есть M_PI в POSIX

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
        double y = sqrt(sin(2 * x));
        double z = sqrt(sqrt( log(tan( y - (PI / 8) )) ));

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
    int n = (int)(x / PI) / 2;
    double remainder = x - (PI * 2 * n);
    return 0 < remainder && remainder < 1.047;
}
