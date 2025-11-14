#include<iostream>
#include<string>
#include<set>
#include<sstream>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input;
    stringstream ss;
    ss << cin.rdbuf();
    set<string> s;
    string word;
    while (ss >> word) {
        string out;
        for (char& c : word) {
            if (isalpha(c))
                out += tolower(c);
            else if (!out.empty()) {
                s.insert(out);
                out.clear();
            }
        }
        if (!out.empty())
            s.insert(out);
    }
    for (auto& i : s) {
        cout << i << '\n';
    }
}
