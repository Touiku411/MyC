#include<iostream>
using namespace std;



int numDigits; // the number of digits of n
// returns the p-th power of d
int power(int d, int p)
{
    if (p == 0)return 1;
    return d * power(d, p - 1);
}
int sumPowerDigits(int n)
{
    if (n == 0)return 0;
    else
        return power(n % 10, numDigits) + sumPowerDigits(n / 10);
}

int main()
{
    int numCases;
    cin >> numCases;
    for (int i = 1; i <= numCases; i++)
    {
        int n;
        cin >> n;

        numDigits = 0; // the number of digits of n
        for (int i = n; i > 0; i /= 10)
            numDigits++;

        if (n == sumPowerDigits(n))
            cout << "Armstrong" << endl;
        else
            cout << "Not Armstrong" << endl;
    }
}

