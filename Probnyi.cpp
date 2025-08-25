#include <stdio.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#include <stdlib.h>

enum nRoots {
    ZeroRoots,
    OneRoot,
    TwoRoots,
    InfRoots,
    NANRoots
};

struct koefficients {
        double a;
        double b;
        double c;
        int n;
        double x1;
        double x2;
};

int SquareSolv (struct koefficients *s);        //this function solves quadratic equasion

int IsNull (double *x);                         // in case of -0

int CompareDoubles(double a, double b);         //returns 1 - if a>b, 0 - if a = b, -1 - if a < b

int Input(struct koefficients *s);

int Output(struct koefficients *s);

int OneTest(struct koefficients Ref);

int RunTest(koefficients Tests[], int Count);

int main () {
    struct koefficients Tests[10] = {{}};
    int i = 0;
    char buffer[256];
    FILE *fp = fopen("tests.txt", "r");
    assert(fp);
    while (fp) {
        while((fgets(buffer, 256, fp)) != NULL) {
            printf("\n");
            sscanf(buffer, "%lg, %lg, %lg, %d, %lg, %lg", &Tests[i].a, &Tests[i].b, &Tests[i].c, &Tests[i].n, &Tests[i].x1, &Tests[i].x2);
            printf("%lg\n", Tests[i].a);
            i++;
        }
        fclose(fp);
    }
    printf("Could'n open this file\n");
    int Count = sizeof(Tests) / sizeof(Tests[0]);
    printf("%d\n", Count);
    printf("%d\n", RunTest(Tests, Count));
    return 0;
}

int Input(struct koefficients *s){
    while (scanf("%lf %lf %lf", &s->a, &s->b, &s->c) != 3) {
        while (getchar() != '\n');
        printf("Let's try one more time.\n");
    }
}

int Output(struct koefficients *s){
    assert(s->n!=NANRoots);
    switch (s->n) {

        case ZeroRoots:
            printf("There are no roots\n");
            break;
        case OneRoot:
            printf("There is one root: ");
            IsNull(&s->x1);
            printf("%lg. \n", s->x1);
            break;
        case TwoRoots:
            printf("Trese are two roots: ");
            IsNull(&s->x1);
            IsNull(&s->x2);
            printf("%lg, %lg. \n", s->x1, s->x2);
            break;
        case InfRoots:
            printf("There are an infinite number of roots.\n");
            break;
        default:
            printf("An error.\n");
            break;
    }
}

int CompareDoubles (double a, double b) {
    if (isnan(a) && isnan(b)) 
        return 0;
    else {
        if (fabs(a - b) < DBL_MIN)
            return 0;
        else
            return (a-b > DBL_MIN) ? 1 : -1;
    }
    
}

int IsNull (double *x) {
    if (!CompareDoubles(*x,0))
        *x = 0;
    return 0;
}

int SquareSolv (struct koefficients *s) {
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
            s->x1 = - s->c / s->b;
            s->n = OneRoot;
        }
    }
    else {

        if (d > 0) {
            s->x1 = (-s->b + sqrt(d)) / 2 / s->a;
            s->x2 = (-s->b - sqrt(d)) / 2 / s->a;
            s->n = TwoRoots;
        }
        else if (!CompareDoubles(d,0)) {
            s->x1 = -s->b / 2 / s->a;
            s->n = OneRoot;
        }
        else s->n = ZeroRoots;
    }
    return 0;
}

int OneTest(struct koefficients Ref) {
    struct koefficients Real = {Ref.a, Ref.b, Ref.c, NANRoots, NAN, NAN};
    SquareSolv(&Real);
    if (!((Ref.n == Real.n && !CompareDoubles(Ref.x1, Real.x1) && !CompareDoubles(Ref.x2, Real.x2)) || 
        (Ref.n == Real.n && !CompareDoubles(Ref.x1, Real.x2) && !CompareDoubles(Ref.x2, Real.x1))) ) {
        printf("FAILED: SquareSolv(%lg, %lg, %lg, %d, %lg, %lg)\n", Ref.a, Ref.b, Ref.c, Ref.n, Ref.x1, Ref.x2);
        printf("-> nRoots = %d, x1 = %lg, x2 = %lg\n", Real.n, Real.x1, Real.x2);
        return 0;
    }
    return 1;
}

int RunTest(koefficients Tests[], int Count) {
    int passed = 0;
    for (int i = 0; i < Count; i++) {
        passed += OneTest(Tests[i]);
    }
    return passed;
}




