/*!
    \file 
    \brief Input and Output module
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "InputOutput.h"
#include "Solver.h"

int CleanBuffer() 
{
    while (getchar() != '\n'){}
    return 0;
}

int Input(struct SolverData *s)
{
    while (scanf("%lf %lf %lf", &s->a, &s->b, &s->c) != 3) {
        CleanBuffer();
        printf("\033[30mLet's try one more time.\033[0m\n");
    }
    return 0;
}

int Output(struct SolverData *s)
{
    assert(s->n!=NANRoots);
    switch (s->n) {

        case ZeroRoots:
            printf("There are no roots\n");
            break;
        case OneRoot:
            printf("There is one root: %lg. \n", s->x1);
            break;
        case TwoRoots:
            printf("Trese are two roots: %lg, %lg. \n", s->x1, s->x2);
            break;
        case InfRoots:
            printf("There are an infinite number of roots.\n");
            break;
        default:
            printf("An error.\n");
            break;
    }
    return 0;
}