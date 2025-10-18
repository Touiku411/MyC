// Polynomial division provided that the quotient and remainder have integer coefficients
#include <iostream>
using namespace std;

// quotient = dividend / divisor; remainder = dividend % divisor provided that
// dividendExpon[ dividendSize - 1 ] >= divisorExpon[ divisorSize - 1 ], and
// neither dividend nor divisor is the zero polynomial
void division(int dividendCoef[], long long int dividendExpon[], int dividendSize,
    int divisorCoef[], long long int divisorExpon[], int divisorSize,
    int quotientCoef[], long long int quotientExpon[], int& quotientSize,
    int remainderCoef[], long long int remainderExpon[], int& remainderSize);

// returns true if and only if polynomial1 == polynomial2
bool equal(int coefficient1[], long long int exponent1[], int size1,
    int coefficient2[], long long int exponent2[], int size2);

// minuend -= subtrahend
void subtraction(int minuendCoef[], long long int minuendExpon[], int& minuendSize,
    int subtrahendCoef[], long long int subtrahendExpon[], int subtrahendSize);

// outputs the specified polynomial
void output(int coefficient[], long long int exponent[], int size);

const int arraySize1 = 20;
const int arraySize2 = 400;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int dividendCoef[arraySize2] = {};
        long long int dividendExpon[arraySize2] = {};
        int dividendSize;
        cin >> dividendSize; // input dividend
        for (int i = dividendSize - 1; i >= 0; i--)
            cin >> dividendCoef[i];
        for (int i = dividendSize - 1; i >= 0; i--)
            cin >> dividendExpon[i];

        int divisorCoef[arraySize1] = {};
        long long int divisorExpon[arraySize1] = {};
        int divisorSize;
        cin >> divisorSize; // input divisor
        for (int i = divisorSize - 1; i >= 0; i--)
            cin >> divisorCoef[i];
        for (int i = divisorSize - 1; i >= 0; i--)
            cin >> divisorExpon[i];

        int quotientCoef[arraySize1] = {};
        long long int quotientExpon[arraySize1] = {};
        int quotientSize = arraySize1;

        int remainderCoef[arraySize2] = {};
        long long int remainderExpon[arraySize2] = {};
        int remainderSize = dividendSize;

        // quotient = dividend / divisor; remainder = dividend % divisor
        division(dividendCoef, dividendExpon, dividendSize,
            divisorCoef, divisorExpon, divisorSize,
            quotientCoef, quotientExpon, quotientSize,
            remainderCoef, remainderExpon, remainderSize);

        output(quotientCoef, quotientExpon, quotientSize);
        output(remainderCoef, remainderExpon, remainderSize);
    }
}

// quotient = dividend / divisor; remainder = dividend % divisor provided that
// dividendExpon[ dividendSize - 1 ] >= divisorExpon[ divisorSize - 1 ], and
// neither dividend nor divisor is the zero polynomial
void division(int dividendCoef[], long long int dividendExpon[], int dividendSize,
    int divisorCoef[], long long int divisorExpon[], int divisorSize,
    int quotientCoef[], long long int quotientExpon[], int& quotientSize,
    int remainderCoef[], long long int remainderExpon[], int& remainderSize)
{
    for (int i = 0; i < dividendSize; i++) {
        remainderCoef[i] = dividendCoef[i];
        remainderExpon[i] = dividendExpon[i];
    }
    quotientSize = 0;
    while (remainderSize > 0 && remainderExpon[remainderSize - 1] >= divisorExpon[divisorSize - 1]) {
        int xishu = remainderCoef[remainderSize - 1] / divisorCoef[divisorSize - 1];
        long long int power = remainderExpon[remainderSize - 1] - divisorExpon[divisorSize - 1];

        quotientCoef[quotientSize] = xishu;
        quotientExpon[quotientSize] = power;
        quotientSize++;
        int tempCoef[arraySize2] = {};
        long long int tempExpon[arraySize2] = {};
        int tempSize = 0;
        for (int i = 0; i < divisorSize ; i++) {
            tempCoef[tempSize] = xishu * divisorCoef[i];
            tempExpon[tempSize] = power + divisorExpon[i];
            tempSize++;
        }
        if (equal(remainderCoef, remainderExpon, remainderSize, tempCoef, tempExpon, tempSize)) {
            remainderSize = 1;
            remainderCoef[0] = 0;
            remainderExpon[0] = 0;
            break;
        }
        subtraction(remainderCoef, remainderExpon, remainderSize, tempCoef, tempExpon, tempSize);          
    }
    for (int i = 0; i < quotientSize / 2; i++) {
        swap(quotientCoef[i], quotientCoef[quotientSize - i - 1]);
        swap(quotientExpon[i], quotientExpon[quotientSize - i - 1]);
    }

}

// returns true if and only if polynomial1 == polynomial2
bool equal(int coefficient1[], long long int exponent1[], int size1,
    int coefficient2[], long long int exponent2[], int size2)
{
    if (size1 != size2)
        return false;

    for (int i = 0; i < size1; i++)
        if (coefficient1[i] != coefficient2[i] || exponent1[i] != exponent2[i])
            return false;

    return true;
}

// minuend -= subtrahend
void subtraction(int minuendCoef[], long long int minuendExpon[], int& minuendSize,
    int subtrahendCoef[], long long int subtrahendExpon[], int subtrahendSize)
{
    int tempCoef[arraySize2] = {};
    long long int tempExpon[arraySize2] = {};
    int tempSize = 0;

    int i = 0, j = 0;

    while (i < minuendSize && j < subtrahendSize) {
        if (minuendExpon[i] < subtrahendExpon[j]) {
            tempCoef[tempSize] = minuendCoef[i];
            tempExpon[tempSize] = minuendExpon[i];
            tempSize++;
            i++;
        }
        else if (minuendExpon[i] > subtrahendExpon[j]) {
            tempCoef[tempSize] = -subtrahendCoef[j];
            tempExpon[tempSize] = subtrahendExpon[j];
            tempSize++;
            j++;
        }
        else {
            int diff = minuendCoef[i] - subtrahendCoef[j];
            if (diff != 0) {
                tempCoef[tempSize] = diff;
                tempExpon[tempSize] = minuendExpon[i];
                tempSize++;
            }
            i++; j++;
        }
    }
    while (i < minuendSize) {
        tempCoef[tempSize] = minuendCoef[i];
        tempExpon[tempSize] = minuendExpon[i];
        tempSize++;
        i++;
    }
    while (j < subtrahendSize) {
        tempCoef[tempSize] = -subtrahendCoef[j];
        tempExpon[tempSize] = subtrahendExpon[j];
        tempSize++;
        j++;
    }

    for (int k = 0; k < tempSize; k++) {
        minuendCoef[k] = tempCoef[k];
        minuendExpon[k] = tempExpon[k];
    }
    minuendSize = tempSize;

}

// outputs the specified polynomial
void output(int coefficient[], long long int exponent[], int size)
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
