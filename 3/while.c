#include "shared.h"

int main()
{
    double step = init();
    
    int max_steps = (to - from) / step;
    int n = 0;

    while(n <= max_steps)
    {
        double x = from + step * n;
        make_table_line(x, f(x));
        n++;
    }

    return 0;
}