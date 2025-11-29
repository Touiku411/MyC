#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double a, b;
    while (cin >> a >> b && a != 0 && b != 0) {
        int cnt = 0;
        for (int i = a; i <= b; ++i) {
            if (sqrt(i) == (int)sqrt(i))
                cnt++;
        }
        cout << cnt << endl;
    }
}
    

