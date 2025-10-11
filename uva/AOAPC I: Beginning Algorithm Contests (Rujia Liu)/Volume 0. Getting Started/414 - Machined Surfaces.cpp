#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

int main()
{
    int N;
    while (cin >> N) {
        cin.ignore();
        if (N == 0)break;
        vector<string> vec(N);
        for (int i = 0; i < N; i++) {
            getline(cin, vec[i]);
        }
        int minleft = 25, minright = 25;
        for (int i = 0; i < N; i++) {
            size_t spacepos = vec[i].find(' ');
            int leftlen = spacepos;
            size_t findX = vec[i].find('X',spacepos);
            int rightlen = vec[i].size() - findX;

            if (leftlen < minleft) 
                minleft = leftlen;
            if (rightlen < minright)
                minright = rightlen;
        }

        int maxLen = 0;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            size_t spacepos = vec[i].find(' ');
            int leftlen = spacepos;
            size_t findX = vec[i].find('X', spacepos);
            int rightlen = vec[i].size() - findX;

            int left = leftlen - minleft;
            int right = rightlen - minright;
            if (left + right > maxLen) {
                maxLen = left + right;
            }
            sum += left + right;
        }
        cout << maxLen * (N - 1) - (sum - maxLen) << endl;
 

    }
}


    
