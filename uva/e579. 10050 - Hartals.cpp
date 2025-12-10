#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    while (N--) {
        int N, P;
        cin >> N >> P;
        map<int, int> days;
        vector<int> zhengdang(P);
        for (int i = 0; i < P; ++i)
            cin >> zhengdang[i];
        for (int i = 0; i < P; ++i) {
            int digit = zhengdang[i];
            int temp = digit;
            while (temp <= N) {
                if (temp % 7 == 0 || temp % 7 == 6) {
                    temp += digit;
                    continue;
                }   
                days[temp]++;
                temp += digit;
            }
        }
        cout << days.size() << endl;
    }
}
    

