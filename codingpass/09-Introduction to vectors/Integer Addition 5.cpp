#include <iostream>
#include <cstring>
#include <vector>
using namespace::std;

// sum = addend + adder
vector< int > addition(vector< int > addend, vector< int > adder);

int main()
{
    char strA[251], strB[251];
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> strA >> strB;

        int addendSize = strlen(strA);
        vector< int > addend(addendSize);
        for (int i = 0; i < addendSize; ++i)
            addend[i] = strA[addendSize - 1 - i] - '0';

        int adderSize = strlen(strB);
        vector< int > adder(adderSize);
        for (int i = 0; i < adderSize; ++i)
            adder[i] = strB[adderSize - 1 - i] - '0';

        vector< int > sum = addition(addend, adder);

        for (int i = sum.size() - 1; i >= 0; i--)
            cout << sum[i];
        cout << endl;
    }
}

// sum = addend + adder
vector< int > addition(vector< int > addend, vector< int > adder)
{
    int sumSize = (addend.size() > adder.size()) ? addend.size() : adder.size();
    vector<int> sum(sumSize);
    for (int i = 0; i < addend.size(); ++i)
        sum[i] = addend[i];
    for (int i = 0; i < adder.size(); ++i)
        sum[i] += adder[i];
    for (int i = 0; i < sum.size() - 1; ++i) {
        if (sum[i] > 9) {
            sum[i] -= 10;
            sum[i + 1] += 1;
        }
    }
    while (sum.size() > 1 && sum.back() == 0) {
        sum.pop_back();
    }
    return sum;
}
