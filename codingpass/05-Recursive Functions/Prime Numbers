#include <iostream>
#include <cmath>
using namespace std;

// returns true if and only if n has a factor in { 2, 3, ..., end }
bool hasFactor(int n, int end)
{
    if (end == 1)return false;

    if (n % end != 0)
        return hasFactor(n, end - 1);
    else
        return true;

}
int main()
{
    int numCases;
    cin >> numCases;
    for (int i = 1; i <= numCases; i++)
    {
        int n;
        cin >> n;

        if (n == 2 || n == 3)
            cout << "prime" << endl;
        else if (hasFactor(n, static_cast<int>(sqrt(n))))
            cout << "composite" << endl;
        else
            cout << "prime" << endl;
    }
}


