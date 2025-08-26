#ifndef Solver_h
#define Solver_h

enum nRoots {
    ZeroRoots,
    OneRoot,
    TwoRoots,
    InfRoots,
    NANRoots
};

struct cfc {
        double a;
        double b;
        double c;
        int n;
        double x1;
        double x2;
};

int SquareSolv (struct cfc *s);                 //this function solves quadratic equasion

int IsNull (double *x);                         // in case of -0

int CompareDoubles (double a, double b);         //returns 1 - if a>b, 0 - if a = b, -1 - if a < b

#endif
