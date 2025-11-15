#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt = 1;
    int N, Q;
    while (cin >> N >> Q && N != 0 && Q != 0) {
        vector<int> N_vec(N);
        vector<int> Q_vec(Q);
        for (int i = 0; i < N; i++)
            cin >> N_vec[i];
        for (int i = 0; i < Q; i++)
            cin >> Q_vec[i];
        cout << "CASE# " << cnt++ << ":\n";
        sort(N_vec.begin(), N_vec.end());
        for (int i = 0; i < Q; i++) {
            bool find = false;
            for (int j = 0; j < N; j++) {
                if (Q_vec[i] == N_vec[j]) {
                    find = true;
                }
                if (find) {
                    cout << Q_vec[i] << " found at " << j + 1 << endl;
                    break;
                }
            }
            if (!find) {
                cout << Q_vec[i] << " not found\n";
            }
        }
    }
    
}
