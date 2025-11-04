#include <iostream>
#include <cstring>
using namespace::std;

struct HugeInt
{
    int size;
    int* digit;
};

// returns true if and only if hugeInt1 == hugeInt2
bool equal(HugeInt hugeInt1, HugeInt hugeInt2);

// difference = minuend - subtrahend provided that minuend >= subtrahend
void subtraction(HugeInt minuend, HugeInt subtrahend, HugeInt& difference);

int main()
{
    char strA[251], strB[251];

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> strA >> strB;

        HugeInt minuend;
        minuend.size = strlen(strA);
        minuend.digit = new int[minuend.size];
        for (int i = 0; i < minuend.size; ++i)
            minuend.digit[i] = strA[minuend.size - 1 - i] - '0';

        HugeInt subtrahend;
        subtrahend.size = strlen(strB);
        subtrahend.digit = new int[subtrahend.size];
        for (int i = 0; i < subtrahend.size; ++i)
            subtrahend.digit[i] = strB[subtrahend.size - 1 - i] - '0';

        HugeInt difference;
        subtraction(minuend, subtrahend, difference);

        for (int i = difference.size - 1; i >= 0; i--)
            cout << difference.digit[i];
        cout << endl;

        delete[] minuend.digit;
        delete[] subtrahend.digit;
        delete[] difference.digit;
    }
}

// returns true if and only if hugeInt1 == hugeInt2
bool equal(HugeInt hugeInt1, HugeInt hugeInt2)
{
    if (hugeInt1.size != hugeInt2.size)
        return false;

    for (int i = 0; i < hugeInt1.size; i++)
        if (hugeInt1.digit[i] != hugeInt2.digit[i])
            return false;

    return true;
}

// difference = minuend - subtrahend provided that minuend >= subtrahend
void subtraction(HugeInt minuend, HugeInt subtrahend, HugeInt& difference)
{
    if (equal(minuend, subtrahend))
    {
        difference.size = 1;
        difference.digit = new int[1];
        difference.digit[0] = 0;
        return;
    }
    int MaxSize = (minuend.size > subtrahend.size) ? minuend.size : subtrahend.size;
    difference.size = MaxSize;
    difference.digit = new int[difference.size]();
    for (int i = 0; i < minuend.size; i++) {
        difference.digit[i] = minuend.digit[i];
    }
    for (int i = 0; i < subtrahend.size; i++) {
        difference.digit[i] -= subtrahend.digit[i];
    }
    for (int i = 0; i < difference.size - 1; i++) {
        if (difference.digit[i] < 0) {
            difference.digit[i] += 10;
            difference.digit[i + 1] -= 1;
        }
    }
    for (int i = difference.size - 1; i >= 0; i--) {
        if (difference.digit[i] != 0)break;
        difference.size--;
    }

}
