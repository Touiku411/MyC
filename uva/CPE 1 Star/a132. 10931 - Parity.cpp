#include <iostream>
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
//2
#include <iostream>
#include <bitset>
using namespace std;


int main()
{
    int I;
    while (cin >> I) {
        if (I == 0) break;
        bitset<32> b(I);
        string b_str = b.to_string();
        b_str = b_str.substr(b_str.find('1'));
        cout << "The parity of " << b_str << " is " << b.count() << " (mod 2).\n";
    }
}


