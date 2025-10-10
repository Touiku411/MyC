#include<iostream>
using namespace std;

// returns the sum of the k-th powers of digits of n,
// where k is the number of digits of n.
int sumPowerDigits(int n);

// returns the p-th power of d
int power(int d, int p);

int numDigits = 0; // the number of digits of n

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

int sumPowerDigits(int n)
{
    if (n == 0)return 0;
    if (n > 0) {
        int digit = n % 10;
        return power(digit,numDigits) + sumPowerDigits(n / 10);
    }
    else
        return 0;

}

// returns the p-th power of d
int power(int d, int p)
{
    if (p == 0)return 1;
    return d * power(d, p - 1);
}
