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
    string input;
    map<string, int> map;
    vector<string> vec;
    while (getline(cin, input)) {
        if (input == "#")break;
        stringstream ss(input);
        string word;
        while (ss >> word) {
            vec.push_back(word);
            string newWord;
            for (char c : word) {
                newWord += tolower(c);
            }
            sort(newWord.begin(), newWord.end());
            map[newWord]++;
        }
    }
    vector<string> result;
    for (auto s : vec) {
        string temp;
        for (char c : s) {
            temp += tolower(c);
        }
        sort(temp.begin(), temp.end());
        if (map[temp] == 1)
            result.push_back(s);
    }
    sort(result.begin(), result.end());
    for (auto i : result) {
        cout << i << endl;
    }
}
