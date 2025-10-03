// Polynomial multiplication
#include <iostream>
using namespace std;

// product = multiplicand * multiplier
void multiplication(long long int multiplicandCoef[], long long int multiplicandExpon[], int multiplicandSize,
    long long int multiplierCoef[], long long int multiplierExpon[], int multiplierSize,
    long long int productCoef[], long long int productExpon[], int& productSize);

// addend += adder
void addition(long long int addendCoef[], long long int addendExpon[], int& addendSize,
    long long int adderCoef[], long long int adderExpon[], int adderSize);

// outputs the specified polynomial
void output(long long int coefficient[], long long int exponent[], int size);

const int arraySize = 10;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        long long int multiplicandCoef[arraySize] = {};
        long long int multiplicandExpon[arraySize] = {};
        int multiplicandSize;
        cin >> multiplicandSize; // input multiplicand
        for (int i = multiplicandSize - 1; i >= 0; i--)
            cin >> multiplicandCoef[i];
        for (int i = multiplicandSize - 1; i >= 0; i--)
            cin >> multiplicandExpon[i];

        long long int multiplierCoef[arraySize] = {};
        long long int multiplierExpon[arraySize] = {};
        int multiplierSize;
        cin >> multiplierSize; // input multiplier
        for (int i = multiplierSize - 1; i >= 0; i--)
            cin >> multiplierCoef[i];
        for (int i = multiplierSize - 1; i >= 0; i--)
            cin >> multiplierExpon[i];

        long long int productCoef[arraySize * arraySize] = {};
        long long int productExpon[arraySize * arraySize] = {};
        int productSize = 1;

        // product = multiplicand * multiplier
        multiplication(multiplicandCoef, multiplicandExpon, multiplicandSize,
            multiplierCoef, multiplierExpon, multiplierSize,
            productCoef, productExpon, productSize);

        output(productCoef, productExpon, productSize);
    }
}

// product = multiplicand * multiplier
void multiplication(long long int multiplicandCoef[], long long int multiplicandExpon[], int multiplicandSize,
    long long int multiplierCoef[], long long int multiplierExpon[], int multiplierSize,
    long long int productCoef[], long long int productExpon[], int& productSize)
{
    productSize = 0;
    int cnt = 0;
    for (int i = 0; i < multiplicandSize; i++) {
        long long int tempCoef[arraySize] = {};
        long long int tempExpon[arraySize] = {};
        int tempSize = 0;
        for (int j = 0; j < multiplierSize; j++) {
            tempCoef[tempSize] = multiplicandCoef[i] * multiplierCoef[j];
            tempExpon[tempSize] = multiplicandExpon[i] + multiplierExpon[j];
            tempSize++;
        }
        cnt++;
        //addition
        if (cnt == 1) {
            for (int k = 0; k < tempSize; k++) {
                productCoef[k] = tempCoef[k];
                productExpon[k] = tempExpon[k];
            }
            productSize = tempSize;
        } 
        else {
            addition(productCoef, productExpon, productSize, tempCoef, tempExpon, tempSize);
        } 
    }
  
}

// addend += adder
void addition(long long int addendCoef[], long long int addendExpon[], int& addendSize,
    long long int adderCoef[], long long int adderExpon[], int adderSize )
{
    long long int tempCoef[arraySize * arraySize] = {};
    long long int tempExpon[arraySize * arraySize] = {};

    int k = 0;
    int i = 0, j = 0;
    while (i < addendSize && j < adderSize) {
        if (addendExpon[i] < adderExpon[j]) {
            tempCoef[k] = addendCoef[i];
            tempExpon[k] = addendExpon[i];
            i++;
            k++;
        }
        else if (addendExpon[i] > adderExpon[j]) {
            tempCoef[k] = adderCoef[j];
            tempExpon[k] = adderExpon[j];
            j++;
            k++;
        }
        else {
            if (addendCoef[i] + adderCoef[j] != 0) {
                tempCoef[k] = addendCoef[i] + adderCoef[j];
                tempExpon[k] = addendExpon[i];
                k++;
            }
            i++;
            j++;
        }
    }
    while (i < addendSize) {
        tempCoef[k] = addendCoef[i];
        tempExpon[k] = addendExpon[i];
        k++;
        i++;
    }
    while (j < adderSize) {
        tempCoef[k] = adderCoef[j];
        tempExpon[k] = adderExpon[j];
        k++;
        j++;
    }
    addendSize = k;

    for (int i = 0; i < k; i++) {
        addendCoef[i] = tempCoef[i];
        addendExpon[i] = tempExpon[i];
    }

}

// outputs the specified polynomial
void output(long long int coefficient[], long long int exponent[], int size)
{
    cout << size << endl;
    cout << coefficient[size - 1];
    for (int i = size - 2; i >= 0; i--)
        cout << " " << coefficient[i];
    cout << endl;

    cout << exponent[size - 1];
    for (int i = size - 2; i >= 0; i--)
        cout << " " << exponent[i];
    cout << endl;
}
