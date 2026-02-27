#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    string space; getline(cin, space);
    for (int i = 0; i < n;++i) {
        map<string, double> trees;
        string input;
        while (getline(cin, input) && !input.empty()) {
            trees[input]++;
        }
        int sum = 0;
        for (auto& i : trees) {
            sum += i.second;
        }
        for (auto& i : trees) {
            cout << i.first << " " << fixed << setprecision(4) << i.second * 100 / sum << endl;
        }
        if (i != n - 1) {
            cout << endl;
        }
    }
}

