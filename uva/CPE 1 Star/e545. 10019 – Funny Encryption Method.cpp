#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int countOnes(int n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) count++;//n % 2 == 1
        n /= 2;                  
    }
    return count;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    while (N--) {
        int n; cin >> n;
        int b1 = countOnes(n);
        int b2 = 0;
        int temp_n = n;
        while (temp_n > 0) {
            int digit = temp_n % 10;
            b2 += countOnes(digit);
            temp_n /= 10;
        }
        cout << b1 << " " << b2 << '\n';
    }
}
    
