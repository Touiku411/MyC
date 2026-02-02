#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bin(int n) {
    if (n != 0) {
        bin(n / 2);
        cout << n % 2;
    }
}
int num(int n) {
    if (n == 0)
        return 0;
    if (n % 2 == 0) {
        return num(n / 2);
    }
    else {
        return 1 + num(n / 2);
    }
}
int main()
{
    int I;
    while (cin >> I) {
        if (I == 0) break;
        cout << "The parity of ";
        bin(I);
        cout << " is " << num(I) << " (mod 2).\n";
    }
}

