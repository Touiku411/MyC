#include<iostream>
#include<string>
#include<map>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    cin.ignore();
    map<string,int> map;
    while (T--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        string country;
        ss >> country;
        map[country]++;
    }
    for (auto& i : map) {
        cout << i.first << " " << i.second << endl;
    }
}
