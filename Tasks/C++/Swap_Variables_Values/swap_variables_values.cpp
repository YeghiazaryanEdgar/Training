#include <iostream>
using namespace std;

void swapValues(double &a, double &b) {
   a = a + b;
   b = a - b;
   a = a - b;
}

int main() {

    double a = 10;
    double b = 20;

    swapValues(a, b);

    cout<<"a: "<< a <<endl;
    cout<<"b: "<< b <<endl;     

    return 0;
}





