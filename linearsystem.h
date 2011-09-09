#ifndef LINEARSYSTEM_H
#define LINEARSYSTEM_H
#include "matrix.h"

class LinearSystem
{
public:
    LinearSystem(int equationsNumber, int variablesNumber);

    Matrix* coefficients;
    Matrix* independentsTerms;
    int equationsNumber;
    int variablesNumber;
    ~LinearSystem();

};

#endif // LINEARSYSTEM_H
