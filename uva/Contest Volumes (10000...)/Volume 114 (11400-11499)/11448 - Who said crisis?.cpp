#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstring>
using std::strlen;

// returns true if and only if hugeInt1 < hugeInt2
bool less(int hugeInt1[], int hugeInt2[], int size1, int size2);

// difference = minuend - subtrahend provided that minuend > subtrahend
void subtraction(int minuend[], int subtrahend[], int difference[],
    int minuendSize, int subtrahendSize, int& differenceSize);

char strA[10000], strB[10000];
int numA[10000], numB[10000], numC[10000];

int main()
{
    int n;
    cin >> n;
    for (int k = 0; k < n; ++k)
    {
        cin >> strA >> strB;

        int sizeA = strlen(strA);
        for (int i = 0; i < sizeA; ++i)
            numA[i] = strA[sizeA - 1 - i] - '0';

        int sizeB = strlen(strB);
        for (int i = 0; i < sizeB; ++i)
            numB[i] = strB[sizeB - 1 - i] - '0';

        int sizeC = 0;
        if (less(numA, numB, sizeA, sizeB))
        {
            cout << "-";
            subtraction(numB, numA, numC, sizeB, sizeA, sizeC);
        }
        else if (less(numB, numA, sizeB, sizeA))
            subtraction(numA, numB, numC, sizeA, sizeB, sizeC);
        else
        {
            sizeC = 1;
            numC[0] = 0;
        }

        for (int i = sizeC - 1; i >= 0; i--)
            cout << numC[i];
        cout << endl;
    }

    return 0;
}

// returns true if and only if hugeInt1 < hugeInt2
bool less(int hugeInt1[], int hugeInt2[], int size1, int size2)
{ 
    if (size1 == size2) {
        for (int i = size1 - 1; i >= 0; i--) {
            if (hugeInt1[i] < hugeInt2[i])
                return true;
            else if (hugeInt1[i] > hugeInt2[i])
                return false;
            else
                continue;
        }   
    }
    else if (size1 < size2) {
        return true;
    }
    return false;
}

// difference = minuend - subtrahend provided that minuend > subtrahend
void subtraction(int minuend[], int subtrahend[], int difference[],
    int minuendSize, int subtrahendSize, int& differenceSize)
{
    if (minuendSize > subtrahendSize)
        differenceSize = minuendSize;
    else
        differenceSize = subtrahendSize;

    while (minuendSize - 1 >= 0 && subtrahendSize - 1 >= 0) {
        if (minuendSize - 1 > subtrahendSize - 1) {
            difference[minuendSize - 1] = minuend[minuendSize - 1];
            minuendSize--;
        }
        else if (minuendSize - 1 < subtrahendSize - 1) {
            difference[subtrahendSize - 1] = -subtrahend[subtrahendSize - 1];
            subtrahendSize--;
        }
        else {
            difference[minuendSize - 1] = minuend[minuendSize - 1] - subtrahend[subtrahendSize - 1];
            minuendSize--;
            subtrahendSize--;
        }
    }
    for (int i = 0; i < differenceSize - 1; i++) {
        if (difference[i] < 0) {
            difference[i] += 10;
            difference[i + 1] -= 1;
        }
    }
    for (int i = differenceSize - 1; i >= 0; i--) {
        if (difference[i] == 0)
            differenceSize--;
        else
            break;
    }
}
//1
//1058327
//67353
