#include <iostream>
#include <vector>
#include <string>
using namespace std;

int maxlen(vector<string>& vec) {
    int maxl = 0;
    for (string& i : vec) {
        maxl = max(maxl, int(i.size()));
    }
    return maxl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string input;
    vector<string> lines;
    while (getline(cin, input)) {
        lines.push_back(input);
    }
    for (int i = 0; i < maxlen(lines); ++i) {
        for (int j = lines.size() - 1; j >= 0; --j) {
            if (i > lines[j].size() - 1) {
                cout << " ";
            }
            else
                cout << lines[j][i];
        } 
        cout << endl;
    }
}
    
