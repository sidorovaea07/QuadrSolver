/*!
    \file 
    \brief Solver module
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <float.h>
#include "Solver.h"

int CompareDoubles (double a, double b) {
    if (isnan(a) && isnan(b))
        return 0;
    else 
    {
        if (fabs(a - b) < DBL_MIN)
            return 0;
        else
            return (a-b > DBL_MIN) ? 1 : -1;
    }

}

int IsNull (double *x) 
{
    if (!CompareDoubles(*x,0))
        *x = 0;
    return 0;
}

int SquareSolv (struct SolverData *s) 
{
    assert(!isnan(s->a));
    assert(!isnan(s->b));
    assert(!isnan(s->c));
    assert(s->x1);
    assert(s->x2);
    double d = s->b * s->b - 4 * s->a * s->c;
    if (!CompareDoubles(s->a, 0))
        {
        if (!CompareDoubles(s->b, 0))
            {
            if (!CompareDoubles(s->c, 0))
                s->n = InfRoots;
            else s->n = ZeroRoots;
        }
        else
            {
            s->x1 = s->x2 = - s->c / s->b;
            IsNull(&s->x1);
            IsNull(&s->x2);
            s->n = OneRoot;
        }
    }
    else 
    {
        if (d > 0) 
        {
            s->x1 = (-s->b + sqrt(d)) / 2 / s->a;
            IsNull(&s->x1);
            s->x2 = (-s->b - sqrt(d)) / 2 / s->a;
            IsNull(&s->x2);
            s->n = TwoRoots;
        }
        else if (!CompareDoubles(d,0)) 
        {
            s->x1 = s->x2 = -s->b / 2 / s->a;
            IsNull(&s->x1);
            IsNull(&s->x2);
            s->n = OneRoot;
        }
        else s->n = ZeroRoots;
    }
    return 0;
}

