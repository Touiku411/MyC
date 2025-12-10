#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
    int N, M;
    while(cin >> N >> M){
        if(N == 0 && M == 0){
            cout << "0 0\n";
            break;
        };
        vector<int> vec(N);
        for(int i = 0 ; i < N ; ++i)
            cin >> vec[i];
        sort(vec.begin(), vec.end(), [M](const int a, const int b){
             int mod_A = a % M;
             int mod_B = b % M;
             if(mod_A != mod_B){
                return mod_A < mod_B;
             }
             bool even_A = (a % 2 == 0);
             bool even_B = (b % 2 == 0);
             if(even_A && even_B){
                return a < b;
             }
             else if(!even_A && !even_B){
                return a > b;
             }
             else{
                if(!even_A){
                    return true;
                }
                else{
                    return false;
                }
             }
        });
        cout << N << " " << M << endl;
        for(int i : vec){
            cout << i << endl;
        }
    }
}
