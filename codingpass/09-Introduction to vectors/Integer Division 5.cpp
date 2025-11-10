#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

// quotient = dividend / divisor; remainder = dividend % divisor
// provided that dividend != 0, divisor != 0 and dividend >= divisor
void division(vector< int > dividend, vector< int > divisor,
    vector< int >& quotient, vector< int >& remainder);

// hugeInt /= 10, or equivalently, shifts right by one position
void divideBy10(vector< int >& hugeInt);

// minuend -= subtrahend
// provided that minuend != 0, subtrahend != 0 and minuend >= subtrahend
void subtraction(vector< int >& minuend, vector< int > subtrahend);

// returns true if and only if hugeInt1 < hugeInt2
// provided that hugeInt1 != 0 and hugeInt2 != 0
bool less(vector< int > hugeInt1, vector< int > hugeInt2);

// returns true if and only if the specified huge integer is zero
bool isZero(vector< int > hugeInt);

const int arraySize = 250;

int main()
{
    char strA[251], strB[251];

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> strA >> strB;

        int dividendSize = strlen(strA);
        vector< int > dividend(dividendSize);
        for (int i = 0; i < dividendSize; ++i)
            dividend[i] = strA[dividendSize - 1 - i] - '0';

        int divisorSize = strlen(strB);
        vector< int > divisor(divisorSize);
        for (int i = 0; i < divisorSize; ++i)
            divisor[i] = strB[divisorSize - 1 - i] - '0';

        vector< int > quotient;
        vector< int > remainder;
        division(dividend, divisor, quotient, remainder);

        for (int i = quotient.size() - 1; i >= 0; i--)
            cout << quotient[i];
        cout << endl;

        for (int i = remainder.size() - 1; i >= 0; i--)
            cout << remainder[i];
        cout << endl;
    }
}

// quotient = dividend / divisor; remainder = dividend % divisor
// provided that dividend != 0, divisor != 0 and dividend >= divisor
void division(vector< int > dividend, vector< int > divisor,
    vector< int >& quotient, vector< int >& remainder)
{
    if (dividend == divisor) {
        quotient.resize(1);
        quotient[0] = 1;
        remainder.resize(1);
        remainder[0] = 0;
        return;
    }
    remainder = dividend;
    vector<int> Buffer;
    Buffer = divisor;
    int n = remainder.size() - divisor.size();
    vector<int> temp(n, 0);
    quotient = temp;
    while (n--)
        Buffer.insert(Buffer.begin(), 0);
    if (less(remainder, Buffer))
        divideBy10(Buffer);
    else
        quotient.resize(temp.size() + 1);
    for (int i = quotient.size() - 1; i >= 0; --i) {
        while (!less(remainder, Buffer) ) {
            subtraction(remainder, Buffer);
            quotient[i]++;
            if (isZero(remainder))
                return;
        }
        divideBy10(Buffer);
    }
}

// hugeInt /= 10, or equivalently, shifts right by one position
void divideBy10(vector< int >& hugeInt)
{
    int size = hugeInt.size();
    if (size == 1)
        hugeInt[0] = 0;
    else
    {
        for (int i = 1; i < size; i++)
            hugeInt[i - 1] = hugeInt[i];
        hugeInt.pop_back();
    }
}

// minuend -= subtrahend
// provided that minuend != 0, subtrahend != 0 and minuend >= subtrahend
void subtraction(vector< int >& minuend, vector< int > subtrahend)
{
    for (int i = 0; i < subtrahend.size(); ++i) {
        minuend[i] -= subtrahend[i];
    }
    for (int i = 0; i < minuend.size() - 1; ++i) {
        if (minuend[i] < 0) {
            minuend[i] += 10;
            minuend[i + 1] -= 1;
        }
    }
    while (minuend.size() > 1 && minuend.back() == 0)
        minuend.pop_back();
}

// returns true if and only if hugeInt1 < hugeInt2
// provided that hugeInt1 != 0 and hugeInt2 != 0
bool less(vector< int > hugeInt1, vector< int > hugeInt2)
{
    if (hugeInt1.size() < hugeInt2.size())return true;
    else if (hugeInt1.size() > hugeInt2.size())return false;


    for (int i = hugeInt1.size() - 1; i >= 0; --i) {
        if (hugeInt1[i] > hugeInt2[i])return false;
        else if (hugeInt1[i] < hugeInt2[i])return true;
    }
    return false;
}



// returns true if and only if the specified huge integer is zero
bool isZero(vector< int > hugeInt)
{
    return hugeInt.size() == 1 && hugeInt[0] == 0;
}
