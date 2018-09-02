#include <iostream>
using namespace std;

class CombineMatrices {
public:

    CombineMatrices(double arr[4][4]) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                multArr[i][j] = (arr)[i][j];
            }
        }
    }


    CombineMatrices operator + (CombineMatrices const &c) {
        double cArr[4][4] = {0};
        CombineMatrices comb(cArr);
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                comb.multArr[i][j] = multArr[i][j] + c.multArr[i][j];
            }
        }

        return comb;
    }

    CombineMatrices operator * (CombineMatrices const &c) {
        double cArr[4][4] = {0};
        CombineMatrices comb(cArr);
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                comb.multArr[i][j] = multArr[i][j] * c.multArr[i][j];
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


    CombineMatrices arr1(array1);
    CombineMatrices arr2(array2);

    CombineMatrices arr3 =  arr2 + arr1;
    CombineMatrices arr4 =  arr2 * arr1;

    arr4.showArray();
    cout<<endl;
    arr3.showArray();

    return 0;
}





