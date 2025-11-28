#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countLen(int n) {
    int cnt = 0;
    while (n != 1) {
        if (n % 2 != 0) {
            n = 3 * n + 1;
        }
        else {
            n /= 2;
        }
        cnt++;
    }
    return cnt + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i, j;
    while (cin >> i >> j) {
        int start = min(i, j);
        int end = max(i, j);
        int maxlen = 0;
        for (int k = start; k <= end; ++k) {
            maxlen = max(maxlen, countLen(k));
        }
        cout << i << " " << j << " " << maxlen << endl;
    }
}
// 遞迴寫法
// int countLen(int n,int cnt) {
//     if (n == 1)return cnt;
//     if (n % 2 != 0)
//         return cnt + countLen(n * 3 + 1, cnt);
//     else 
//         return cnt + countLen(n / 2, cnt);
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int i, j;
//     while (cin >> i >> j) {
//         int start = min(i, j);
//         int end = max(i, j);
//         int maxlen = 0;
//         int cnt = 1;
//         for (int k = start; k <= end; ++k) {
//             maxlen = max(maxlen, countLen(k , cnt));
//         }
//         cout << i << " " << j << " " << maxlen << endl;
//     }
// }
    

