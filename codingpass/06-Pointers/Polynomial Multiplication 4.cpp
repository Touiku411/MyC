// Polynomial multiplication
#include <iostream>
using namespace std;

// product = multiplicand * multiplier
void multiplication(long long int* multiplicandCoef, long long int* multiplicandExpon, int multiplicandSize,
    long long int* multiplierCoef, long long int* multiplierExpon, int multiplierSize,
    long long int*& productCoef, long long int*& productExpon, int& productSize);

// addend += adder
void addition(long long int*& addendCoef, long long int*& addendExpon, int& addendSize,
    long long int* adderCoef, long long int* adderExpon, int adderSize);

// outputs the specified polynomial
void output(long long int* coefficient, long long int* exponent, int size);

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int multiplicandSize;
        cin >> multiplicandSize; // input multiplicand
        long long int* multiplicandCoef = new long long int[multiplicandSize]();
        long long int* multiplicandExpon = new long long int[multiplicandSize]();
        for (int i = multiplicandSize - 1; i >= 0; i--)
            cin >> multiplicandCoef[i];
        for (int i = multiplicandSize - 1; i >= 0; i--)
            cin >> multiplicandExpon[i];

        int multiplierSize;
        cin >> multiplierSize; // input multiplier
        long long int* multiplierCoef = new long long int[multiplierSize]();
        long long int* multiplierExpon = new long long int[multiplierSize]();
        for (int i = multiplierSize - 1; i >= 0; i--)
            cin >> multiplierCoef[i];
        for (int i = multiplierSize - 1; i >= 0; i--)
            cin >> multiplierExpon[i];

        int productSize;
        long long int* productCoef;
        long long int* productExpon;
        // product = multiplicand * multiplier
        multiplication(multiplicandCoef, multiplicandExpon, multiplicandSize,
            multiplierCoef, multiplierExpon, multiplierSize,
            productCoef, productExpon, productSize);

        output(productCoef, productExpon, productSize);

        delete[] multiplicandCoef;
        delete[] multiplicandExpon;
        delete[] multiplierCoef;
        delete[] multiplierExpon;
        delete[] productCoef;
        delete[] productExpon;
    }
}

// product = multiplicand * multiplier
void multiplication(long long int* multiplicandCoef, long long int* multiplicandExpon, int multiplicandSize,
    long long int* multiplierCoef, long long int* multiplierExpon, int multiplierSize,
    long long int*& productCoef, long long int*& productExpon, int& productSize)
{
    productCoef = nullptr;
    productExpon = nullptr;
    productSize = 0;
    for (int i = 0; i < multiplierSize; ++i) {
        long long int* tempCoef = new long long int[multiplicandSize];
        long long int* tempExpon = new long long int[multiplicandSize];
        int tempSize = 0;
        for (int j = 0; j < multiplicandSize; ++j) {
            tempCoef[tempSize] = multiplierCoef[i] * multiplicandCoef[j];
            tempExpon[tempSize] = multiplierExpon[i] + multiplicandExpon[j];
            tempSize++;
        }
        addition(productCoef, productExpon, productSize, tempCoef, tempExpon, tempSize);
        delete[] tempCoef;
        delete[] tempExpon;
    }
}

// addend += adder
void addition(long long int*& addendCoef, long long int*& addendExpon, int& addendSize,
    long long int* adderCoef, long long int* adderExpon, int adderSize)
{
    long long int* tempCoef = new long long[addendSize + adderSize];
    long long int* tempExpon = new long long[addendSize + adderSize];
    int tempSize = 0;
    int i = 0, j = 0;
    while (i < addendSize && j < adderSize)
    {
        if (addendExpon[i] < adderExpon[j]) {
            tempCoef[tempSize] = addendCoef[i];
            tempExpon[tempSize] = addendExpon[i];
            tempSize++;
            i++;
        }
        else if (addendExpon[i] > adderExpon[j]) {
            tempCoef[tempSize] = adderCoef[j];
            tempExpon[tempSize] = adderExpon[j];
            tempSize++;
            j++;
        }
        else {
            long long int Sum = addendCoef[i] + adderCoef[j];
            if (Sum != 0) {
                tempCoef[tempSize] = Sum;
                tempExpon[tempSize] = addendExpon[i];
                tempSize++;
            }
            i++, j++;
        }
    }
    while (i < addendSize) {
        tempCoef[tempSize] = addendCoef[i];
        tempExpon[tempSize] = addendExpon[i];
        tempSize++;
        i++;
    }
    while (j < adderSize) {
        tempCoef[tempSize] = adderCoef[j];
        tempExpon[tempSize] = adderExpon[j];
        tempSize++;
        j++;
    }
    delete[] addendCoef;
    delete[] addendExpon;
    addendCoef = tempCoef;
    addendExpon = tempExpon;
    addendSize = tempSize;
}
// outputs the specified polynomial
void output(long long int* coefficient, long long int* exponent, int size)
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
