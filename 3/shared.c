#include "shared.h"

const double from = 0.0, to = 3.0;

double f(double x)
{
    if (0 <= x && x <= 1.5)
        return pow(2, x) - 2.0 + x*x;
    if (1.5 < x && x <= 3)
        return sqrt(x) * exp(-x*x);
    
    return NAN;
}

double init()
{
    double step;
    printf("Шаг таблицы: ");
    scanf("%lf", &step);

    printf("    x    |    f(x)  \n");
    printf("---------+----------\n");

    return step;
}

void make_table_line(double x, double fx)
{
    printf("%8lf | %9lf\n", x, fx);
}