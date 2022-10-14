#ifndef FUNCTION_H
#define FUNCTION_H

#include <math.h>
#include <stdio.h>

extern const double from, to;

double f(double x);
double init(); // return step
void make_table_line(double x, double fx);

#endif