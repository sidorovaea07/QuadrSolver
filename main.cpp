#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <assert.h>

enum nRoots {
    ZeroRoots,
    OneRoot,
    TwoRoots,
    InfRoots,
    NANRoots
};

//TODO: add to struct x1 x2 nRoots
// Return value of function better give for error status of running this function
// enum

/*

int main(){
// Create all values;
 //Input();
 //Test();
 //Solve();
 //Output();
}

*/

struct koefficients {
        double a;
        double b;
        double c;
        double x1;
        double x2;
        enum nRoots n;
};

int SquareSolv (struct koefficients *s);        //˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜

int IsNull (double *x);                         // ˜˜ ˜˜˜˜˜˜ -0

int CompareDoubles(double a, double b);         //˜˜˜˜˜˜˜˜˜˜ 1 - if a>b, 0 - if a = b, -1 - if a < b

int Input(struct koefficients *s);

int Output(struct koefficients *s);
//------------------------------
int main()
{
    struct koefficients s = {NAN, NAN, NAN, NAN, NAN, NANRoots};

    printf("˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜ ax^2 + bx + c = 0.\n");
    Input(&s);
    SquareSolv(&s);
    Output(&s);
    return 0;
}
//------------------------------
int Input(struct koefficients *s){
    while (scanf("%lf %lf %lf", &s->a, &s->b, &s->c) != 3) {
        while (getchar() != '\n');
        printf("˜˜˜˜˜˜˜˜˜˜ ˜˜˜ ˜˜˜.\n");
    }
}

int Output(struct koefficients *s){
    assert(s->n!=NANRoots);
    switch (s->n) {

        case ZeroRoots:
            printf("˜˜˜˜˜˜˜ ˜˜˜\n");
            break;
        case OneRoot:
            printf("˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜ 1 ˜˜˜˜˜˜˜: ");
            IsNull(&s->x1);
            printf("%lg. \n", s->x1);
            break;
        case TwoRoots:
            printf("˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜ 2 ˜˜˜˜˜˜˜: ");
            IsNull(&s->x1);
            IsNull(&s->x2);
            printf("%lg, %lg. \n", s->x1, s->x2);
            break;
        case InfRoots:
            printf("˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜.\n");
            break;
        default:
            printf("˜˜˜˜˜˜.\n");
            break;
    }
}

int CompareDoubles (double a, double b) {
    if (fabs(a - b) < DBL_MIN)
        return 0;
    else
        return (a-b > DBL_MIN) ? 1 : -1;
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
    assert(s->x1 != NULL);
    assert(s->x2 != NULL);
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

int TestSS()
    {
    double x1 = 0, x2 = 0;
    int nRoots = SquareSolv(1, -5, 6, &x1, &x2); //2,3
    if (!(nRoots == 2 && CompareDoubles(x1, 2) && CompareDoubles(x2, 3)))
        printf("FAILED: SS(-1, 5, 6) -> %d, x1 = %lf, x2 = %lf (should be x1=2, x2=3)\n", nRoots, x1, x2);
    }



