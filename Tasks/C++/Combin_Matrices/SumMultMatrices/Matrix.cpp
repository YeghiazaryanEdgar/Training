#include <iostream>
#include <cstdlib>
#include <random>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(const int r, const int c, string n) {
    cout<< "Constructor called. " << n <<"\n";
    rows = r;
    cols = c;
    name = n;
    M = new int*[r];
    for(int i=0; i<rows; i++) {
        M[i] = new int[cols];
    }
}

void Matrix::fillMatrix() const {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            M[i][j] = rand() % 10;
        }
    }
}

void Matrix::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << M[i][j] << '\t';
        }
        cout << endl;
    }
}

Matrix Matrix::operator + (const Matrix& O) {
    Matrix Sum(rows, cols, "Matrix 3");
    cout<< "Sum of Matrices" <<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Sum.M[i][j] = M[i][j] + O.M[i][j];
        }
    }
    return Sum;
}

Matrix Matrix::operator * (const Matrix& O) {
    Matrix Mult(rows, O.cols, "Matrix 4");
    cout<< "Mult of Matrices" <<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < O.cols; j++) {
            int sum = 0;
            for (int k = 0; k < cols; k++) {
//                    cout<< M[i][k] <<" " << O.M[k][j] <<" ";
                sum += M[i][k] * O.M[k][j];
            }
            Mult.M[i][j] = sum;
        }

    }
    return Mult;
}

Matrix::~Matrix() {
    cout << "Destructor called. " << name <<"\n";
    for (int i = 0; i < rows; ++i) {
        delete M[i];
    }
    delete M;
}
