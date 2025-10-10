#include<iostream>
#include<string>
#include<vector>
using namespace std;

//1 . 2 x 3 W 

char numToChar(int num) {
    switch (num) {
        case 0:return ' ';
        case 1:return '.';
        case 2:return 'x';
        case 3:return 'W';
        default: return ' ';
    }
}
int main()
{

    int N; cin >> N;
    while (N--) {
        vector<vector<int>> IDX(50, vector<int>(40));
        vector<vector<char>> DNA(50, vector<char>(40, ' '));
        vector<int> vec(10);
        for (int i = 0; i < 10; i++) {
            cin >> vec[i];
        }
        IDX[0][19] = 1;
        DNA[0][19] = '.';

        for (int k = 1; k < 50; k++) {
            for (int t = 0; t < 40; t++) {
                int left = (t == 0 ? 0 : IDX[k - 1][t - 1]);
                int mid = IDX[k - 1][t];
                int right = (t == 39 ? 0 : IDX[k - 1][t + 1]);
                
                IDX[k][t] = vec[left + mid + right];
                DNA[k][t] = numToChar(IDX[k][t]);
            }
        }

        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 40; j++) {
                cout << DNA[i][j];
            }
            cout << endl;
        }
        if(N) cout << endl;

    }
    
   

}


