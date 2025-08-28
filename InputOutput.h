/*!
    \file
    \brief Header for Input and Output
*/

#ifndef InputOutput_h
#define InputOutput_h

//----------------------------------------------------------
//! Cleans Buffer
//----------------------------------------------------------
int CleanBuffer();

//----------------------------------------------------------
//! Requests the coefficients and verifies the input
//----------------------------------------------------------
int Input(struct SolverData *s);

//----------------------------------------------------------
//! Outputs the number of roots and the roots if any
//----------------------------------------------------------
int Output(struct SolverData *s);

#endif
