#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        int x, y;
        y = (a - b) / 2;
        x = a - y;
        if ((a + b) % 2 == 0 && x >= 0 && y >= 0) {
            cout << x << " " << y << endl;
        }
        else {
            cout << "impossible\n";
        }
    }
}
