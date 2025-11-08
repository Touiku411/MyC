#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;

struct HugeInt
{
    int size;
    int* digit;
};

// quotient = dividend / divisor; remainder = dividend % divisor
// provided that dividend != 0, divisor != 0 and dividend >= divisor
void division(HugeInt dividend, HugeInt divisor, HugeInt& quotient, HugeInt& remainder);

// hugeInt /= 10, or equivalently, shifts right by one position
void divideBy10(HugeInt& hugeInt);

// minuend -= subtrahend
// provided that minuend != 0, subtrahend != 0 and minuend >= subtrahend
void subtraction(HugeInt& minuend, HugeInt subtrahend);

// returns true if and only if hugeInt1 < hugeInt2
// provided that hugeInt1 != 0 and hugeInt2 != 0
bool less(HugeInt hugeInt1, HugeInt hugeInt2);

// return true if and only if hugeInt1 == hugeInt2
// provided that hugeInt1 != 0 and hugeInt2 != 0
bool equal(HugeInt hugeInt1, HugeInt hugeInt2);

// returns true if and only if the specified huge integer is zero
bool isZero(HugeInt hugeInt);

const int arraySize = 250;

int main()
{
    char strA[251], strB[251];

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> strA >> strB;

        HugeInt dividend;
        dividend.size = strlen(strA);
        dividend.digit = new int[dividend.size]();
        for (int i = 0; i < dividend.size; ++i)
            dividend.digit[i] = strA[dividend.size - 1 - i] - '0';

        HugeInt divisor;
        divisor.size = strlen(strB);
        divisor.digit = new int[divisor.size]();
        for (int i = 0; i < divisor.size; ++i)
            divisor.digit[i] = strB[divisor.size - 1 - i] - '0';

        HugeInt quotient;
        HugeInt remainder;
        division(dividend, divisor, quotient, remainder);

        for (int i = quotient.size - 1; i >= 0; i--)
            cout << quotient.digit[i];
        cout << endl;

        for (int i = remainder.size - 1; i >= 0; i--)
            cout << remainder.digit[i];
        cout << endl;

        delete[] dividend.digit;
        delete[] divisor.digit;
        delete[] quotient.digit;
        delete[] remainder.digit;
    }
}

// quotient = dividend / divisor; remainder = dividend % divisor
// provided that dividend != 0, divisor != 0 and dividend >= divisor
void division(HugeInt dividend, HugeInt divisor, HugeInt& quotient, HugeInt& remainder)
{
    remainder.size = dividend.size;
    remainder.digit = new int[remainder.size]();

    for (int i = 0; i < dividend.size; ++i) {
        remainder.digit[i] = dividend.digit[i];
    }
    int n = dividend.size - divisor.size;
    HugeInt Buffer;
    Buffer.size = remainder.size;
    Buffer.digit = new int[Buffer.size]();
    int k = divisor.size;//4
    int i = Buffer.size;//7
    while (k > 0) {
        Buffer.digit[--i] = divisor.digit[--k];
    }
     
    quotient.size = n;
    if (less(dividend, Buffer)) {
        divideBy10(Buffer);
    }
    else
        quotient.size++;
    quotient.digit = new int[quotient.size]();

    for (int k = quotient.size - 1; k >= 0; --k) {
        while (less(Buffer, remainder) || equal(Buffer,remainder)) {
            subtraction(remainder, Buffer);
            quotient.digit[k]++;
            if (isZero(remainder))
                return;
        }
        divideBy10(Buffer);
    }

}

// hugeInt /= 10, or equivalently, shifts right by one position
void divideBy10(HugeInt& hugeInt)
{
    if (hugeInt.size == 1)
        hugeInt.digit[0] = 0;
    else
    {
        for (int i = 1; i < hugeInt.size; i++)
            hugeInt.digit[i - 1] = hugeInt.digit[i];

        hugeInt.size--;
        hugeInt.digit[hugeInt.size] = 0;
    }
}

// minuend -= subtrahend
// provided that minuend != 0, subtrahend != 0 and minuend >= subtrahend
void subtraction(HugeInt& minuend, HugeInt subtrahend)
{
    if (equal(minuend, subtrahend)){
        minuend.size = 1;
        minuend.digit = new int[1];
        minuend.digit[0] = 0;
        return;
    }
    for (int i = 0 ;i < subtrahend.size; ++i) {
        minuend.digit[i] -= subtrahend.digit[i];
    }
    for (int i = 0; i < minuend.size - 1; ++i) {
        if (minuend.digit[i] < 0) {
            minuend.digit[i] += 10;
            minuend.digit[i + 1] -= 1;
        }
    }
    for (int i = minuend.size - 1; i >= 0; --i) {
        if (minuend.digit[i] != 0)break;
        minuend.size--;
    }
}

// returns true if and only if hugeInt1 < hugeInt2
// provided that hugeInt1 != 0 and hugeInt2 != 0
bool less(HugeInt hugeInt1, HugeInt hugeInt2)
{
    if (hugeInt1.size < hugeInt2.size)
        return true;
    else if(hugeInt1.size > hugeInt2.size)
        return false;

    for (int i = hugeInt1.size - 1; i >= 0; --i) {
        if (hugeInt1.digit[i] < hugeInt2.digit[i])
            return true;
        else if (hugeInt1.digit[i] > hugeInt2.digit[i])
            return false;
    }
    return false;
}

// return true if and only if hugeInt1 == hugeInt2
// provided that hugeInt1 != 0 and hugeInt2 != 0
bool equal(HugeInt hugeInt1, HugeInt hugeInt2)
{
    if (hugeInt1.size != hugeInt2.size)
        return false;

    for (int i = hugeInt1.size - 1; i >= 0; i--)
        if (hugeInt1.digit[i] != hugeInt2.digit[i])
            return false;

    return true;
}

// returns true if and only if the specified huge integer is zero
bool isZero(HugeInt hugeInt)
{
    return hugeInt.size == 1 && hugeInt.digit[0] == 0;
}
