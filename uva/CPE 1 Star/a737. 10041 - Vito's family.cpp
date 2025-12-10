#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    while (N--) {
        int n; cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; ++i)
            cin >> vec[i];

        sort(vec.begin(), vec.end());
        int mid;
        if (vec.size() % 2 == 0) {
            mid = vec[(vec.size() - 1) / 2];
        }
        else {
            mid = vec[vec.size() / 2];
        }
        int distance = 0;
        for (int i = 0; i < vec.size(); ++i) {
            distance += abs(mid - vec[i]);
        }
        cout << distance << endl;
    }
}
    

