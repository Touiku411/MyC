#include <iostream>
using namespace std;

int digits[12] = {};
// returns true iff the subarray digits[ first .. last ] is a palindrome
bool isPalindrome(int first, int last)
{
    if (first >= last) return true;
    if (digits[first] == digits[last])
        return isPalindrome(first + 1, last - 1);
    else
        return false;


}
int main()
{
    int numCases;
    cin >> numCases;
    for (int i = 1; i <= numCases; i++)
    {
        int n;
        cin >> n;

        int length = 0;
        for (int i = n; i > 0; i /= 10)
            digits[length++] = i % 10;

        if (isPalindrome(0, length - 1))
            cout << "palindrome" << endl;
        else
            cout << "non-palindrome" << endl;
    }
}

