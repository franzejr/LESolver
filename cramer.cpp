#include "cramer.h"
#include <string>
#include "linearsystem.h"
#include <iostream>

Cramer::Cramer(LinearSystem* system)
{

}

Cramer::~Cramer()
{
}


double* Cramer::execute(LinearSystem* system)
{
    answer = new double[3];
    double determinant = system->coefficients->det3By3();
    std::cout<<determinant;
//Getting the determinants from the coefficients Matrix and answer
   for(int i = 0; i<3; i++){
        answer[i] = this->changeCols(system,i).det3By3()/determinant;
        std::cout<<answer[i];
    }

    return answer;

}

Matrix Cramer::changeCols(LinearSystem* system,int col){
    Matrix* buffer = new Matrix(system->equationsNumber, system->variablesNumber);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j<3; j++){
            buffer->setElement(i,j,system->coefficients->getElement(i,j) );
        }
    }

    for(int i = 0; i < 3; i++){
        buffer->setElement(i,col,system->independentsTerms->getElement(i,0));
    }


//    for(int i = 0; i <3;i++){
//        buffer.setElement(i,col,system->independentsTerms->getElement(i,0));
//    }
    return *buffer;
}
