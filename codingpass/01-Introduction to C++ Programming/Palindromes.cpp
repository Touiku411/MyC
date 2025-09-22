#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string input; cin >> input;
    string s = input;
    reverse(s.begin(), s.end());
    if (input == s)
        cout << "palindrome\n";
    else
        cout << "non-palindrome\n";
}
