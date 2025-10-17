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

// returns true if and only if the specified polynomial is the zero polynomial
bool isZero(long long int coefficient[], int size);

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

    for (int i = 0; i < multiplierSize; i++) {
        long long int tempCoef[arraySize * arraySize] = {};
        long long int tempExpon[arraySize * arraySize] = {};
        int tempSize = 0;
        for (int j = 0; j < multiplicandSize; j++) {
            tempCoef[tempSize] = multiplierCoef[i] * multiplicandCoef[j];
            tempExpon[tempSize] = multiplierExpon[i] + multiplicandExpon[j];
            tempSize++;
        }
        if(isZero(productCoef,productSize)){
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
//低.....高
// addend += adder
void addition(long long int addendCoef[], long long int addendExpon[], int& addendSize,
    long long int adderCoef[], long long int adderExpon[], int adderSize)
{
    long long int tempCoef[arraySize * arraySize] = {};
    long long int tempExpon[arraySize * arraySize] = {};
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

    for (int i = 0; i < tempSize; i++) {
        addendCoef[i] = tempCoef[i];
        addendExpon[i] = tempExpon[i];
    } 
    addendSize = tempSize;
}

// returns true if and only if the specified polynomial is the zero polynomial
bool isZero(long long int coefficient[], int size)
{
    return (size == 1 && coefficient[0] == 0);
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
