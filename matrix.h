#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{

public:
    Matrix(int r, int c);
    //Setters
    void setDimensions(int,int);
    void setElement(int x, int y, double element);

    //Getters
    int getNumberRows() const;
    int getNumberColumns() const;
    double getElement (int x, int y) const;

    //Determinant
    double det() const;
    double det3By3() const;

    //Properties
    bool isSquare() const;

    Matrix& operator =(const Matrix& M);

private:
    int rows;               // Number of rows;
    int columns;            // Number of columns;
    double* matrix;
};


#endif // MATRIX_H
