#ifndef LESOLVER_H
#define LESOLVER_H
#include <string>
#include "linearsystem.h"

using namespace std;

class LESolver
{
public:
    LESolver();
    virtual ~LESolver();
    virtual double* execute(LinearSystem* system)=0;
    double* answer;

};

#endif // LESOLVER_H
