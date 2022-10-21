#include <stdio.h>
#include "shared.h"

int main()
{
    double step = init();

    for (double x = from; x <= to; x += step)
        make_table_line(x, f(x));
    
    return 0;
}

/*

      ( Начало )
           |
        ___L__
       / step |
       -------
          |
     /----------\
    /    x =     \
  +> from,to,step >------------+
  | \            /             |
  |  \----------/              |
  |       +                ( Конец )
  |       |     
  |   ++------++
  |   || f(x) ||
  |   ++------++
  |       |     
  |     __L____ 
  |    / f(x) / 
  |    -------  
  |       |     
  |       |      
  --------+
*/