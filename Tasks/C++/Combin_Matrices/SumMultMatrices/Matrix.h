#ifndef MATRICES_MATRIX_H
#define MATRICES_MATRIX_H
#include <iostream>
using namespace std;

class Matrix {
public:
    Matrix(const int r, const int c, string n);
    void fillMatrix() const;
    void print() const;
    Matrix operator + (const Matrix& O);
    Matrix operator * (const Matrix& O);
    ~Matrix();
private:
    int **M;
    int rows;
    int cols;
    string name;
};

#endif
