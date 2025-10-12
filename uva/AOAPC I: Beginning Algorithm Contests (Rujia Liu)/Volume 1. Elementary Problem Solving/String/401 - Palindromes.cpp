#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

char Mirror(char c) {
    switch (c) {
        case 'A': return 'A';
        case 'E': return '3';
        case 'H': return 'H';
        case 'I': return 'I';
        case 'J': return 'L';
        case 'L': return 'J';
        case 'M': return 'M';
        case 'O': return 'O';
        case 'S': return '2';
        case 'T': return 'T';
        case 'U': return 'U';
        case 'V': return 'V';
        case 'W': return 'W';
        case 'X': return 'X';
        case 'Y': return 'Y';
        case 'Z': return '5';
        case '1': return '1';
        case '2': return 'S';
        case '3': return 'E';
        case '5': return 'Z';
        case '8': return '8';
        default:return ' ';
    } 
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;

    while (getline(cin, input) && !input.empty()) {
        string zeroToO;
        for (char c : input) {
            if (c == '0')
                c = 'O';
            zeroToO += c;
        }
        bool ispalindrome = false;
        bool ismirrored = false;

        string rev = zeroToO;
        reverse(rev.begin(), rev.end());
        if (zeroToO == rev)ispalindrome = true;

        string mir;
        for (char c : rev) {
            c = Mirror(c);
            mir += c;
        }  
        if (mir == zeroToO)ismirrored = true;

        if (ispalindrome && ismirrored)
            cout << input << " -- is a mirrored palindrome.\n";
        else if (!ispalindrome && ismirrored)
            cout << input << " -- is a mirrored string.\n";
        else if (ispalindrome && !ismirrored)
            cout << input << " -- is a regular palindrome.\n";
        else
            cout << input << " -- is not a palindrome.\n";
        cout << endl;
    }
 
}

