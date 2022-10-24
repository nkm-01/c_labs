#include <stdio.h>
#include <math.h>
#include <values.h>

const double from = 0.0, to = M_PI;

double f(double x)
{
    if (x <= M_PI / 2.0)
        return pow(2, x) - 2.0 + x*x;

    return sqrt(x) * exp(-x*x);
}

int main()
{
    double presicion;
    printf("Введите точность: ");
    scanf("%lf", &presicion);

    int steps = 1;

    double integral = f((to - from) / 2.0);
    double twice_integral;

    double delta;
    do
    {
        steps <<= 1;
        twice_integral = 0.0l;
        double step = (to - from) / steps;

        for (int i = 0; i < steps; i++)
            twice_integral += f(from + step * i + step / 2.0) * step;

        delta = fabs((twice_integral - integral) / 3.0);
        integral = twice_integral;
    } while (delta > presicion);

    printf("Интеграл: %lf\n", twice_integral);

    return 0;
}