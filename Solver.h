/*!
    \file
    \brief Header for Solver
*/

#ifndef Solver_h
#define Solver_h

//----------------------------------------------------------
//! Sets values for the number of roots of a given equation
//----------------------------------------------------------
enum nRoots {
    ZeroRoots = 0,
    OneRoot = 1,
    TwoRoots = 2,
    InfRoots = 3,
    NANRoots = 4
};

//--------------------------------------------------------------------------------------
//! Sets the struct for the coefficients, number of roots and roots of a given equation
//--------------------------------------------------------------------------------------
struct SolverData {
        double a;
        double b;
        double c;
        int n;
        double x1;
        double x2;
};

//--------------------------------------------------------------------------------------
//! Compares doubles
//! 
//! @param [in] a - the first number 
//! @param [in] b - the second number
//! 
//! @return 1 - if a > b, 0 - if a == b, -1 - if a < b
//--------------------------------------------------------------------------------------
int CompareDoubles (double a, double b);         

//--------------------------------------------------------------------------------------
//! Returns "0" in case of "-0"
//! 
//! @param [in] x - number 
//! 
//! @param [out] x - the final number
//!
//! @return 0
//--------------------------------------------------------------------------------------
int IsNull (double *x);                          

//--------------------------------------------------------------------------------------
//! Solves a square equation ax^2 + bx + c = 0
//! 
//! @param [in] a - coefficient 
//! @param [in] b - coefficient
//! @param [in] c - coefficient
//! @param [out] x1 - the first root
//! @param [out] x2 - the second root
//!
//! @return Number of roots
//--------------------------------------------------------------------------------------
int SquareSolv (struct SolverData *s);           

#endif
