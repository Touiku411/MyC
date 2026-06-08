#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    int T; cin >> T;
    while(T--){
        int l, m;
        cin >> l >> m;
        queue<int> left;
        queue<int> right;
        string ins;
        while(m--){
            int x; cin >> x;
            cin >> ins;
            if(ins == "left"){
                left.push(x);
            }
            else if(ins == "right"){
                right.push(x);
            }
        }
        int res = 0;
        while(!left.empty() || !right.empty()){
            int capacity = l * 100;
            if(res % 2 == 0 && !left.empty()){
                while(true){
                    if(left.empty() || capacity - left.front() < 0){
                        break;
                    }
                    capacity -= left.front();
                    left.pop();
                }
            }
            else if(res % 2 == 1 && !right.empty()){
                while(true){
                    if(right.empty() || capacity - right.front() < 0){
                        break;
                    }
                    capacity -= right.front();
                    right.pop();
                }
            }
            res++;
        }
        cout << res << '\n';
    }
}


