#include <iostream>
using namespace std;

void fib0( int n );
void fib1(int numb, int a, int b);
void fib2();

int main() {

    int n;
    cin >> n;
    
    fib0(n);

    //fib1(n, 0, 1);

    /*
    for(int i=0; i<n; i++) {
        fib2();
    }
     */

    return 0;
}

void fib0( int n ) {
    int a=0, b=1;
    for(int i=0; i<n; i++) {
        cout<< "a: " << a <<endl;
        b = a + b;
        a = b - a;
    }
}

void fib1(int numb, int a, int b) {
    if(numb < 1) return;
    cout<< a <<endl;
    return fib1(--numb, (b + a) - a, b + a);
}

void fib2() {
    static int a = 0, b = 1;
    b = a + b;
    a = b - a;
    cout<<a <<endl;
}



