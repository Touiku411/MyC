#include <iostream>
#include <vector>
#include <string>
#include <map>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    cin.ignore();
    map<char, int> m;
    while (N--) {
        string input;
        getline(cin, input);
        for (char c : input) {
            if (isalpha(c)) {
                m[toupper(c)]++;
            }
        }
    }
    vector<pair<char, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        if (a.second != b.second)
            return a.second > b.second;
        else
            return a.first < b.first;

        });
    for (auto& i : vec) {
        cout << i.first << " " << i.second << '\n';
    }
}
    
