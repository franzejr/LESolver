#ifndef CRAMER_H
#define CRAMER_H
#include "linearsystem.h"
#include "lesolver.h"
#include <string>

class Cramer : public LESolver
{
public:
    Cramer(LinearSystem* system);
    virtual ~Cramer();
    double* execute(LinearSystem* system);
    Matrix changeCols(LinearSystem* system,int col);

};

#endif // CRAMER_H
