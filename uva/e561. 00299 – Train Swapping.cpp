#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    while (N--) {
        int L; cin >> L;
        vector<int> train(L);
        for (int i = 0; i < L; ++i)
            cin >> train[i];
        int cnt = 0;
        for (int i = 0; i < L; ++i) {
            for (int j = i + 1; j < L; ++j) {
                if (train[i] > train[j])
                    cnt++;
            }
        }
        cout << "Optimal train swapping takes " << cnt << " swaps.\n";
    }
}
    
