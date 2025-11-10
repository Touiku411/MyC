#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;

class HugeInt
{
public:
    int size;
    int* digit;

    // quotient = dividend / divisor; remainder = dividend % divisor
    // provided that dividend != 0, divisor != 0 and dividend >= divisor
    void division(HugeInt& divisor, HugeInt& quotient, HugeInt& remainder);

    // hugeInt /= 10, or equivalently, shifts right by one position
    void divideBy10();

    // minuend -= subtrahend
    // provided that minuend != 0, subtrahend != 0 and minuend >= subtrahend
    void subtraction(HugeInt& subtrahend);

    // returns true if and only if hugeInt1 < hugeInt2
    // provided that hugeInt1 != 0 and hugeInt2 != 0
    bool less(HugeInt& hugeInt2);

    // return true if and only if hugeInt1 == hugeInt2
    // provided that hugeInt1 != 0 and hugeInt2 != 0
    bool equal(HugeInt& hugeInt2);

    // returns true if and only if the specified huge integer is zero
    bool isZero();
};

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
        dividend.division(divisor, quotient, remainder);

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
void HugeInt::division(HugeInt& divisor, HugeInt& quotient, HugeInt& remainder)
{
    if (this-> equal(divisor)) {
        quotient.size = 1;
        quotient.digit = new int[1];
        quotient.digit[0] = 1;
        remainder.size = 1;
        remainder.digit = new int[1];
        remainder.digit[0] = 0;
        return;
    }
    remainder.size = this->size;
    remainder.digit = new int[remainder.size];
    for (int i = 0; i < this->size; ++i) {
        remainder.digit[i] = this->digit[i];
    }
    HugeInt Buffer;
    Buffer.digit = new int[this->size]();
    Buffer.size = this->size;
    int k = Buffer.size;//7
    int t = divisor.size;//4
    while (t > 0) {
        Buffer.digit[--k] = divisor.digit[--t];
    }
    quotient.size = this->size - divisor.size;

    if (remainder.less(Buffer))
        Buffer.divideBy10();
    else
        quotient.size++;
    quotient.digit = new int[quotient.size]();

    for (int k = quotient.size - 1; k >= 0; --k) {
        while (!remainder.less(Buffer)) {
            remainder.subtraction(Buffer);
            quotient.digit[k]++;
            if (remainder.isZero()) {
                delete[] Buffer.digit;
                return;

            }
        }
        Buffer.divideBy10();
    }
    delete[] Buffer.digit;
}

// hugeInt /= 10, or equivalently, shifts right by one position
void HugeInt::divideBy10()
{
    if (size == 1)
        digit[0] = 0;
    else
    {
        for (int i = 1; i < size; i++)
            digit[i - 1] = digit[i];

        size--;
        digit[size] = 0;
    }
}

// minuend -= subtrahend
// provided that minuend != 0, subtrahend != 0 and minuend >= subtrahend
void HugeInt::subtraction(HugeInt& subtrahend)
{
    if (this->equal(subtrahend)) {
        this->digit[0] = 0;
        this->size = 1;
        return;
    }
    for (int i = 0; i < subtrahend.size; ++i) {
        this->digit[i] -= subtrahend.digit[i];
    }
    for (int i = 0; i < this->size - 1; ++i) {
        if (this->digit[i] < 0) {
            this->digit[i] += 10;
            this->digit[i + 1] -= 1;
        }
    }
    while (this->size > 1 && this->digit[this->size - 1] == 0) {
        this->size--;
    }

}

// returns true if and only if hugeInt1 < hugeInt2
// provided that hugeInt1 != 0 and hugeInt2 != 0
bool HugeInt::less(HugeInt& hugeInt2)
{
    if (this->size < hugeInt2.size)return true;
    else if (this->size > hugeInt2.size) return false;

    for (int i = this->size - 1; i >= 0; --i) {
        if (this->digit[i] < hugeInt2.digit[i])
            return true;
        else if (this->digit[i] > hugeInt2.digit[i])
            return false;
    }
    return false;
}

// return true if and only if hugeInt1 == hugeInt2
// provided that hugeInt1 != 0 and hugeInt2 != 0
bool HugeInt::equal(HugeInt& hugeInt2)
{
    if (size != hugeInt2.size)
        return false;

    for (int i = size - 1; i >= 0; i--)
        if (digit[i] != hugeInt2.digit[i])
            return false;

    return true;
}

// returns true if and only if the specified huge integer is zero
bool HugeInt::isZero()
{
    return size == 1 && digit[0] == 0;
}
