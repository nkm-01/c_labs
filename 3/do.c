#include <stdio.h>

#include "shared.h"

int main()
{
	double step = init();
	int max_steps = (to - from) / step;

	for (int i = 0; i <= max_steps; i++)
	{
		double x = from + step * i;
		make_table_line(x, f(x));
	}

	return 0;
}