#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "Solver.h"
#include "TesterReader.h"

struct cfc HandMadeTests[] = {
        { 1, -5, 6, TwoRoots, 3, 2},
        { 1, 0, -4, TwoRoots, 2, -2},
        { 0, 0, 0, InfRoots, NAN, NAN},
        { 0, 1, 0, OneRoot, 0, 0},
        { 0, 0, 1, ZeroRoots, NAN, NAN},
        { 1, 2, 1, OneRoot, -1, -1},
        { 1, 3, 2, TwoRoots, -1, -2}, 
        {0, 1, 1, OneRoot, -1, -1},
        {1, 5, 0, TwoRoots, 0, -5}
    };

int OneTest(struct cfc Ref) {
    struct cfc Real = {Ref.a, Ref.b, Ref.c, NANRoots, NAN, NAN};
    SquareSolv(&Real);
    if (!((Ref.n == Real.n && !CompareDoubles(Ref.x1, Real.x1) && !CompareDoubles(Ref.x2, Real.x2)) ||
        (Ref.n == Real.n && !CompareDoubles(Ref.x1, Real.x2) && !CompareDoubles(Ref.x2, Real.x1))) ) {
        printf("FAILED: SquareSolv(%lg, %lg, %lg, %d, %lg, %lg) ", Ref.a, Ref.b, Ref.c, Ref.n, Ref.x1, Ref.x2);
        printf("-> nRoots = %d, x1 = %lg, x2 = %lg\n", Real.n, Real.x1, Real.x2);
        return 0;
    }
    return 1;
}

int RunHandTest() {
    int Count = sizeof (HandMadeTests) / sizeof (HandMadeTests[0]);
    int passed = 0;
    for (int i = 0; i < Count; i++) {
        passed += OneTest(HandMadeTests[i]);
    }
    return passed;
}

int TestsReader() {
    struct cfc Tests = {NAN, NAN, NAN, NANRoots, NAN, NAN};
    int passed = 0;
    FILE *fp = fopen("tests.txt", "r");
    if (fp) {
        while((fscanf(fp, "%lg %lg %lg %d", &Tests.a, &Tests.b, &Tests.c, &Tests.n) ) == 4) {
        switch (Tests.n) {
            case 1: 
            case 2: fscanf(fp, "%lg %lg", &Tests.x1, &Tests.x2); break;
            default: break;
        }
        passed += OneTest(Tests);
        Tests = {NAN, NAN, NAN, NANRoots, NAN, NAN};
        }
    }
    else {
        printf("Trese is no file with tests founded.\n");
    }    
    fclose(fp);
    return passed;
}
