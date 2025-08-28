/*!
    \file
    \brief Header for Tester and Reader
*/

#ifndef TesterReader_h
#define TesterReader_h

//--------------------------------------------------------------------
//! Compares the expected data with received data and error conditions
//--------------------------------------------------------------------
int OneTest(struct SolverData Ref);

//---------------------------------------------------------------------
//! Calls the function OneTest() to test handmade tests
//---------------------------------------------------------------------
int RunHandTest();

//---------------------------------------------------------------------
//! Reads the provided file line by line and tests the received data
//---------------------------------------------------------------------
int TestsReader();

#endif