#include "matrix.h"

Matrix::Matrix(int r,int c)
{
    rows = r;
    columns = c;

    matrix = new double[rows*columns];
}

void Matrix::setDimensions(int m, int n) {
    rows = m; columns = n;
    delete[] matrix;
    matrix = new double[m*n];

}
int   Matrix::getNumberRows() const {return rows;}
int   Matrix::getNumberColumns() const {return columns;}

void Matrix::setElement(int x, int y, double element)
{
    matrix[x*columns + y] = element;
}


bool Matrix::isSquare() const
{
        if(getNumberColumns()==getNumberRows()) return true;
        return false;
}

double Matrix::det() const{
    return 0;
}

double Matrix::getElement(int x, int y) const
{
    return matrix[x*columns + y];
}

double Matrix::det3By3() const{

    return this->getElement(0,0)*(this->getElement(1,1)*this->getElement(2,2) - this->getElement(1,2)*this->getElement(2,1))
            - this->getElement(0,1)*(this->getElement(1,0)*this->getElement(2,2) - this->getElement(1,2)*this->getElement(2,0))
            + this->getElement(0,2)*(this->getElement(1,0)*this->getElement(2,1) - this->getElement(1,1)*this->getElement(2,0));


}

//Trying use the = operator
Matrix& Matrix::operator =(const Matrix& M){

    if(this != &M){
        this->columns = M.columns;
        this->rows = M.rows;

        int tamanho = (this->columns)*(this->rows);
        this->matrix = new double[tamanho];

        for(int i = 0; i <  tamanho; i++){
            this->matrix[i] = M.matrix[i];
        }
    }

    return *this;
}

