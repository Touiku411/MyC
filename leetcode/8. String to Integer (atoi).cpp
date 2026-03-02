#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        if (s.empty())return 0;
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i == n)return 0;
        int sign = 1;
        if (s[i] == '+') {
            i++;
        }
        else if (s[i] == '-') {
            i++;
            sign = -1;
        }
        long long result = 0;
        for (int k = i; k < n; ++k) {
            if (isdigit(s[k])) {
                result = result * 10 + (s[k] - '0');
                if (sign * result <= INT_MIN) {
                    return INT_MIN;
                }
                if (sign * result >= INT_MAX) {
                    return INT_MAX;
                }
            }
            else
                break;
        }
        return sign * result;
    }
};
int main() {
    Solution s;
    string str;
    while(getline(cin, str))
    cout << s.myAtoi(str) << endl;
}
