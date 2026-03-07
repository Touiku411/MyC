#include <iostream>
using namespace std;
//cout << n + (n / 2) << endl;就是答案
int main() {
    int n;
    while (cin >> n) {
        int ans = n;
        int empty = n;
        while (empty >= 3) {
            ans += empty / 3;
            empty = empty / 3 + empty % 3;
        }
        if (empty == 2) {
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
