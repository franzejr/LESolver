#include "linearsystem.h"

LinearSystem::LinearSystem(int equationsNumber, int variablesNumber)
    :equationsNumber(equationsNumber), variablesNumber(variablesNumber)
{
    coefficients = new Matrix(equationsNumber,variablesNumber);
    independentsTerms = new Matrix(equationsNumber,1);


}

LinearSystem::~LinearSystem(){
    for (int i = 0; i < equationsNumber; i++) {
                    delete[] &coefficients[i];
            }
            delete[] coefficients;
            delete[] independentsTerms;
}
