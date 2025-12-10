#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

bool isJolly(vector<int> vec) {
    int t = 1;
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == t) {
            t++;
        }
        else {
            return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> vec(n);
        for (int i = 0; i < n ; ++i) {
            cin >> vec[i];
        }
        vector<int> ab;
        for (int i = 0; i < n - 1; ++i) {
            ab.push_back(abs(vec[i] - vec[i + 1]));
        }
        sort(ab.begin(), ab.end());
        if (isJolly(ab)) {
            cout << "Jolly\n";
        }
        else
        {
            cout << "Not jolly\n";
        }
    }
}
    
