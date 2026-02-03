#include <iostream>
#include <string>
using namespace std;

string getSum(string& s) {
    int sum = 0;
    for (char c : s) {
        sum += c - '0';
    }
    return to_string(sum);
}
int main()
{
    string input;
    while (cin >> input && input != "0") {
        string str = input;
        int degree = 0;
        if (str == "9") {
            degree = 1;
        }
        while (str.size() > 1) {
            str = getSum(str);
            degree++;
        }
        if (str == "9") {
            cout << input << " is a multiple of 9 and has 9-degree " << degree << ".\n";
        }
        else {
            cout << input << " is not a multiple of 9.\n";
        }
    }
}

