#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (m < 2 || n < 2) {
            cout << "Boring!\n";
            continue;
        }
        vector<int> vec;
        while (n % m == 0) {
            vec.push_back(n);
            n /= m;
        }
        if (n == 1) {
            for (int i : vec) {
                cout << i << " ";
            }
            cout << 1 << endl;
        }
        else {
            cout << "Boring!\n";
        }
    }
}
