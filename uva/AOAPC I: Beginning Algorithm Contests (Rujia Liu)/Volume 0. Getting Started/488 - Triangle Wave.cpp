#include<iostream>
#include<string>
#include<vector>
#include <sstream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    while (N--) {
        int A, F; cin >> A >> F;
        while (F--) {
            for (int i = 0; i < A; i++) {
                for (int j = 0; j <= i; j++) {
                    cout << i + 1;
                }
                cout << endl;
            }
            for (int i = A - 1; i > 0; i--) {
                for (int j = i; j > 0; j--) {
                    cout << i;
                }
                cout << endl;
            }
            if(F > 0)cout << endl;
        }
        if(N > 0)cout << endl;
    }
 
}

