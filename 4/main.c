#include <stdio.h>
#include <math.h>

const double from = 0.0, to = 3.0;

double f(double x)
{
    if (0 <= x && x <= 1.5)
        return pow(2, x) - 2.0 + x*x;
    if (1.5 < x && x <= 3)
        return sqrt(x) * exp(-x*x);
    
    return NAN;
}

int main()
{

}