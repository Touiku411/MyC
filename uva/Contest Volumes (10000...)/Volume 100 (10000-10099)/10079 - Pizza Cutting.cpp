#include <iostream>
using namespace std;
int main()
{
    long long n;
    while (cin >> n) {
        if (n < 0)continue;
        cout << 2 + ((n + 2) * (n - 1) / 2) << endl;
    }
}
