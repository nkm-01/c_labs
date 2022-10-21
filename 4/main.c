#include <stdio.h>
#include <math.h>
#include <values.h>

const double from = 0.0, to = 3.0;

double f(double x)
{
    if (0 <= x && x <= M_PI / 2.0)
        return pow(2, x) - 2.0 + x*x;
    if (M_PI / 2.0 < x && x <= M_PI)
        return sqrt(x) * exp(-x*x);
    
    return NAN;
}

int main()
{
    double presicion;
    printf("Введите точность: ");
    scanf("%lf", &presicion);

    double step = (to + from) / 2.0;

    double integral = f(step);
    double twice_integral;

    double delta;
    do
    {
        for ()
    } while (delta > presicion)
}