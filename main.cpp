#include <stdio.h>
#include <math.h>
#include "Solver.h"
#include "TesterReader.h"
#include "InputOutput.h"

int main () {
    
    struct cfc s = {NAN, NAN, NAN, NANRoots, NAN, NAN};
    int passed = TestsReader();
    int handpassed = RunHandTest();
    printf("\033[35mHANDPassed %d.\033[0m\n", handpassed);
    printf("\033[35mPassed %d.\033[0m\n", passed);

    printf("Enter \"s\" to start\n");
    while (getchar() == 's') {
        printf("Enter the coefficients of the quadratic equation in the format ax^2 + bx + c = 0.\n");
        Input(&s);
        SquareSolv(&s);
        Output(&s);
        printf("Enter \"s\" to start again.\n");
        getchar();
    }
    return 0;
}
