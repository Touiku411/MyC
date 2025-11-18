// Polynomial addition
#include <iostream>
using namespace std;

// sum = addend + adder
void addition(long long int* addendCoef, long long int* addendExpon, int addendSize,
    long long int* adderCoef, long long int* adderExpon, int adderSize,
    long long int*& sumCoef, long long int*& sumExpon, int& sumSize);

// outputs the specified polynomial
void output(long long int* coefficient, long long int* exponent, int size);

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int addendSize;
        cin >> addendSize;
        long long int* addendCoef = new long long int[addendSize];
        long long int* addendExpon = new long long int[addendSize];
        for (int i = addendSize - 1; i >= 0; i--)
            cin >> addendCoef[i];
        for (int i = addendSize - 1; i >= 0; i--)
            cin >> addendExpon[i];

        int adderSize;
        cin >> adderSize;
        long long int* adderCoef = new long long int[adderSize];
        long long int* adderExpon = new long long int[adderSize];
        for (int i = adderSize - 1; i >= 0; i--)
            cin >> adderCoef[i];
        for (int i = adderSize - 1; i >= 0; i--)
            cin >> adderExpon[i];

        int sumSize;
        long long int* sumCoef;
        long long int* sumExpon;
        addition(addendCoef, addendExpon, addendSize,
            adderCoef, adderExpon, adderSize,
            sumCoef, sumExpon, sumSize);

        output(sumCoef, sumExpon, sumSize);

        delete[] addendCoef;
        delete[] addendExpon;
        delete[] adderCoef;
        delete[] adderExpon;
        delete[] sumCoef;
        delete[] sumExpon;
    }
}

// sum = addend + adder
void addition(long long int* addendCoef, long long int* addendExpon, int addendSize,
    long long int* adderCoef, long long int* adderExpon, int adderSize,
    long long int*& sumCoef, long long int*& sumExpon, int& sumSize)
{
    sumCoef = new long long int[addendSize + adderSize];
    sumExpon = new long long int[addendSize + adderSize];
    int k = 0;
    int i = 0, j = 0;
    while (i < addendSize && j < adderSize) {
        if (addendExpon[i] > adderExpon[j]) {
            sumCoef[k] = adderCoef[j];
            sumExpon[k] = adderExpon[j];
            j++;
            k++;
        }
        else if (adderExpon[j] > addendExpon[i]) {
            sumCoef[k] = addendCoef[i];
            sumExpon[k] = addendExpon[i];
            i++;
            k++;
        }
        else {
            long long int Sum = addendCoef[i] + adderCoef[j];
            if (Sum != 0) {
                sumCoef[k] = Sum;
                sumExpon[k] = addendExpon[i];
                k++;
            }
            i++; j++;
        }
    }
    while (i < addendSize) {
        sumCoef[k] = addendCoef[i];
        sumExpon[k] = addendExpon[i];
        k++;
        i++;
    }
    while (j < adderSize) {
        sumCoef[k] = adderCoef[j];
        sumExpon[k] = adderExpon[j];
        k++;
        j++;
    }
    sumSize = k;
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
