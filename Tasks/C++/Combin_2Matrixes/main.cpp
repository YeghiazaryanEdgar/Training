#include <iostream>
using namespace std;

class CombineArrays {
public:

    CombineArrays(double arr[4][4]) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                multArr[i][j] = (arr)[i][j];
            }
        }
    }


    CombineArrays operator + (CombineArrays const &c) {
        double cArr[4][4] = {0};
        CombineArrays comb(cArr);
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                comb.multArr[i][j] = multArr[i][j] + c.multArr[i][j];
            }
        }

        return comb;
    }

    void showArray() {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                cout<< multArr[i][j] << ", ";
            }
            cout<< endl;
        }
    }

private:
    double multArr[4][4];
};



int main() {

    double array1[][4] = {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,16}
    };

    double array2[][4] = {
            {100,200,300,400},
            {500,600,700,800},
            {900,100,200,300},
            {700,600,500,400}
    };


    CombineArrays arr1(array1);
    CombineArrays arr2(array2);
    CombineArrays arr3 =  arr2 + arr1;

    arr3.showArray();

    return 0;
}





