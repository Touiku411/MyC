#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double v, t;
    while (cin >> v >> t) {
        cout << 2 * v * t << endl;
    }
}
