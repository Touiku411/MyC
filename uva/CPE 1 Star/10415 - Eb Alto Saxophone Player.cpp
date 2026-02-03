#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
    vector<vector<int>> vec = {
        {0,0,1,1,1,0,0,1,1,1,1},
        {0,0,1,1,1,0,0,1,1,1,0},
        {0,0,1,1,1,0,0,1,1,0,0},
        {0,0,1,1,1,0,0,1,0,0,0},
        {0,0,1,1,1,0,0,0,0,0,0},
        {0,0,1,1,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0,0},
        {0,1,1,1,1,0,0,1,1,1,0},
        {0,1,1,1,1,0,0,1,1,0,0},
        {0,1,1,1,1,0,0,1,0,0,0},
        {0,1,1,1,1,0,0,0,0,0,0},
        {0,1,1,1,0,0,0,0,0,0,0},
        {0,1,1,0,0,0,0,0,0,0,0}
    };
    map<char, int> map = {
        {'c',0},
        {'d',1},
        {'e',2},
        {'f',3},
        {'g',4},
        {'a',5},
        {'b',6},
        {'C',7},
        {'D',8},
        {'E',9},
        {'F',10},
        {'G',11},
        {'A',12},
        {'B',13}
    };
    int t; cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        vector<int> cnt(11, 0);
        vector<int> cur(11, 0);
        for (char c : line) {
            int idx = map[c];
            //vec[idx] vec[0]
            for (int i = 1; i <= 10; ++i) {
                if (cur[i] == 0 && vec[idx][i] == 1) {
                    cnt[i]++;
                }
            }
            cur = vec[idx];
        }
        for (int i = 1; i <= 10; ++i) {
            cout << cnt[i] << " ";
        }
        cout << endl;
    }
}

