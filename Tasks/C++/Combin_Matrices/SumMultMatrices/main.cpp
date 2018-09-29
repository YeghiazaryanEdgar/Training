#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Matrix.h"
using namespace std;

int main() {
    srand(time(0));
    int rows1, cols1, rows2, cols2;
    cout<< "Enter rows1, cols1 \n";
    cin >> rows1 >> cols1;
    cout<< "Enter rows2, cols2 \n";
    cin >> rows2 >> cols2;


    Matrix M1(rows1, cols1, "Matrix 1");
    M1.fillMatrix();
    M1.print();
    cout<<"****************" <<endl;

    Matrix M2(rows2, cols2, "Matrix 2");
    M2.fillMatrix();
    M2.print();
    cout<<"****************" <<endl;

    if(rows1 == rows2 && cols1 == cols2) {
        Matrix M3 = M1 + M2;
        M3.print();
        cout<<"****************" <<endl;
    }
    if(cols1 == rows2) {
        Matrix M4 = M1 * M2;
        M4.print();
        cout<<"****************" <<endl;
    }
    return 0;
}
