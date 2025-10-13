#include<iostream>
#include<string>
#include<vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    stringstream ss;
    ss << cin.rdbuf();
    string word;
    vector<string> vec;
    while (ss >> word) {
        string newWord;
        bool exist = false;
        for (char c : word) {
            if (isalpha(c)) {
                newWord += tolower(c);
            }
            else if (!newWord.empty()) {
                vec.push_back(newWord);
                newWord.clear();
            }
        }
        if(!newWord.empty())
            vec.push_back(newWord);
    }
    std::sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (auto c : vec) {
        cout << c << '\n';
    }

    
    
    
    
}

