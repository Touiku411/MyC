#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

int maxLen(vector<string>& vec) {
    int maxLen = 0;
    for (string s : vec) {
        int cur_Len = s.length();
        maxLen = max(cur_Len, maxLen);
    }
    return maxLen;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        vector<string> words(n);
        for (int i = 0; i < n; ++i)
            cin >> words[i];

        sort(words.begin(), words.end());
        int L = maxLen(words);
        int colums = 62 / (L + 2);
        int rows = (n + colums - 1) / colums;
        cout << "------------------------------------------------------------\n";
        for (int i = 0; i < rows; ++i) {
            for (int j =  0; j < colums; ++j) {
                int index = i + j * rows;
                if (index < n) {
                    string name = words[index];
                    cout << name;
                    int padding = 0;
                    if (j == colums - 1) 
                        padding = L - name.length();
                    else 
                        padding = L + 2 - name.length();                 
                    for (int i = 0; i < padding; ++i)
                        cout << " ";
                }
            } 
            cout << endl;
        }
 
       
    }
}
