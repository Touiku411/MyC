#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    stringstream ss;
    ss << cin.rdbuf();
    string str = ss.str();
    bool find = false;
    for (char c : str) {
        if (c == '"') {
            find = !find;
            if (find) {
                cout << "``";
            }
            else{
                cout << "''";
            }
        }
        else {
            cout << c;
        }
    }
}
    
