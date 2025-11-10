#include <iostream>
#include <cstring>
#include <vector>
using namespace::std;

// difference = minuend - subtrahend provided that minuend >= subtrahend
vector< int > subtraction(vector< int > minuend, vector< int > subtrahend);

int main()
{
    char strA[251], strB[251];

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> strA >> strB;

        int minuendSize = strlen(strA);
        vector< int > minuend(minuendSize);
        for (int i = 0; i < minuendSize; ++i)
            minuend[i] = strA[minuendSize - 1 - i] - '0';

        int subtrahendSize = strlen(strB);
        vector< int > subtrahend(subtrahendSize);
        for (int i = 0; i < subtrahendSize; ++i)
            subtrahend[i] = strB[subtrahendSize - 1 - i] - '0';

        vector< int > difference = subtraction(minuend, subtrahend);

        for (int i = difference.size() - 1; i >= 0; i--)
            cout << difference[i];
        cout << endl;
    }
}
// difference = minuend - subtrahend provided that minuend >= subtrahend
vector< int > subtraction(vector< int > minuend, vector< int > subtrahend)
{
    if (minuend == subtrahend) {
        minuend.resize(1);
        minuend[0] = 0;
        return minuend;
    }
    for (int i = 0; i < subtrahend.size(); ++i) {
        minuend[i] -= subtrahend[i];
    }
    for (int i = 0; i < minuend.size() - 1; ++i) {
        if (minuend[i] < 0) {
            minuend[i] += 10;
            minuend[i + 1] -= 1;
        }
    }
    while (minuend.size() > 1 && minuend.back() == 0) {
        minuend.pop_back();
    }
    return minuend;
}
