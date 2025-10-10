#include <iostream>
using namespace std;

// find the sum of all the even integers in the range [ a, b ]
// provided that both a and b are positive even integers, and a <= b
int evenSum(int a, int b);

int main()
{
    int numCases;
    cin >> numCases;
    for (int i = 1; i <= numCases; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == b && a % 2 == 1)
            cout << 0 << endl;
        else
            cout << evenSum(a, b) << endl;
    }
}

// find the sum of all the even integers in the range [ a, b ]
// provided that both a and b are positive even integers, and a <= b
int evenSum(int a, int b)
{
    if (a > b)return 0;

    if (a % 2 == 0)
        return a + evenSum(a + 1, b);
    else
        return evenSum(a + 1, b);

}
