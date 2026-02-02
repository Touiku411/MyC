#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> rev(vector<long long>& vec) {
    vector<long long> temp = vec;
    reverse(temp.begin(), temp.end());
    return temp;
}
bool cmp(vector<vector<long long>>& vec) {
    int i = 0;
    int j = vec.size() - 1;
    while (i <= j) {
        if (vec[i] != rev(vec[j])) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main()
{
    int T;
    cin >> T;
    for (int cnt = 1; cnt <= T; cnt++) {
        char c1, c2;
        int N;
        cin >> c1 >> c2 >> N;
        vector<vector<long long>> vec(N, vector<long long>(N, 0));
        bool negative = false;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> vec[i][j];
                if (vec[i][j] < 0) {
                    negative = true;
                }
            }
        }
        cout << "Test #" << cnt << ": ";
        if (negative) {
            cout << "Non-symmetric.\n";
            continue;
        }
        if (cmp(vec)) {
            cout << "Symmetric.\n";
        }
        else {
            cout << "Non-symmetric.\n";
        }
    }
    
}

