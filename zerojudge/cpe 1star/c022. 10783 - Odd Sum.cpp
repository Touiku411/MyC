#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    int cnt = 1;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int sum = 0;
        for (int i = a; i <= b; ++i) {
            if (i % 2 != 0)
                sum += i;
        }
        cout << "Case " << cnt++ << ": " << sum << endl;
    }
}
    

