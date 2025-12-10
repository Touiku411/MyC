#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int a, b;
    while (cin >> a >> b) {
        cout << abs(a - b) << endl;
    }
}
