#include<iostream>
#include<string>
#include<vector>
#include <sstream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    vector<string> vec;
    int col = 0;
    int row = 0;
    while (getline(cin, input)) {
        int len = input.length();
        col = max(len, col);
        vec.push_back(input);
    }

    row = vec.size();
    for (int j = 0; j < col; j++) {
        for (int i = row - 1; i >= 0; i--) {
            if (j < vec[i].length())
                cout << vec[i][j];
            else
                cout << ' ';
        }
        cout << endl;
    }

}

