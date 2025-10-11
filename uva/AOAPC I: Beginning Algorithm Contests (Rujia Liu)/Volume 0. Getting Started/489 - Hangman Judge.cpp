#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

int main()
{
    int N;
    string ans,guess;
    while (cin >> N) {
        if (N == -1)break;
        cin >> ans >> guess;
        cout << "Round " << N << "\n";
        int lose = 7;
        set<char> s;
        set<char> used;
        for (int i = 0; i < ans.length(); i++) {
            s.insert(ans[i]);
        }
        for (char c : guess) {
            if (used.count(c))continue;
            used.insert(c);

            if (s.count(c)) {
                s.erase(c);
                if (s.empty())break;
            }
            else {
                lose--;
                if (lose == 0) break;
            }
        }

        if (s.empty())
            cout << "You win.\n";
        else if (lose == 0)
            cout << "You lose.\n";
        else
            cout << "You chickened out.\n";

    }

}


    
