#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void nums(int& even, int& odd, vector<int> vec){
    for(int i : vec){
        if(i % 2 == 0)
            even++;
        else
            odd++;
    }
}
void oddpos(vector<int> vec, int& n){
    for(int i = 0;i< vec.size();++i){
        if(vec[i] % 2 != 0){
            n = i;
            break;
        }
    }
}
void evenpos(vector<int> vec, int& n){
    for(int i = 0;i< vec.size();++i){
        if(vec[i] % 2 == 0){
            n = i;
            break;
        }
    }
}
int main()
{
	int T;
	while(cin >> T && T != 0){
        vector<vector<int>> grid(T,vector<int>(T));
        for(int i = 0 ; i < T;++i){
            for(int j = 0;j < T;++j){
                cin >> grid[i][j];
            }
        }
        vector<int> rows;
        vector<int> cols;//T
        for(int i = 0 ; i < T;++i){
            int sum_r = 0;
            int sum_c = 0;
            for(int j = 0;j < T;++j){
                sum_r += grid[i][j];
                sum_c += grid[j][i];
            }
            rows.push_back(sum_r);
            cols.push_back(sum_c);
        }
        int even_r = 0, odd_r = 0;
        int even_c = 0, odd_c = 0;
        nums(even_r, odd_r, rows);
        nums(even_c, odd_c, cols);
        if((even_r == 0 && even_c == 0) || (odd_r==0 && odd_c == 0)){
            cout << "OK\n";
        }
        else if( even_r == even_c && odd_r == odd_c && min(even_r , odd_r) == 1){
            int x, y;
            if(odd_r == 1){
                oddpos(rows, x);
                oddpos(cols, y);
            }
            else if(even_r == 1){
                evenpos(rows, x);
                evenpos(cols, y);
            }
            cout << "Change bit (" << x + 1 << "," << y + 1 << ")\n";
        }
        else{
            cout << "Corrupt\n";
        }
	}
}
