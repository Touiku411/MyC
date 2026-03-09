#include <iostream>
#include <vector>
using namespace std;

pair<int, int> sum(string& s) {
    int oddSum = 0 , evenSum = 0;
    for (int i = s.length() - 1; i >= 0; i -= 2) {
        oddSum += s[i] - '0';
    }
    for (int i = s.length() - 2; i >= 0; i -= 2) {
        evenSum += s[i] - '0';
    }
    return { oddSum, evenSum };
}
int main() {
    string input;
    while (cin >> input) {
        if (input == "0")break;
        auto i = sum(input);
        cout << input;
        if ((i.first - i.second) % 11 == 0) {
            cout << " is a multiple of 11.\n";
        }
        else {
            cout << " is not a multiple of 11.\n";
        }
    }
}
