#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    int cnt = 1;
    while(cin >> line){
        cout << "Case " << cnt++ << ":\n";
        int T;
        cin >> T;
        vector<int> group(line.size());
        for(int i = 1; i < line.size(); ++i){
            if(line[i] == line[i - 1]){
                group[i] = group[i - 1];
            }
            else{
                group[i] = group[i - 1] + 1;
            }
        }
        while (T--)
        {
            int i, j;
            cin >> i >> j;
            int start = min(i, j);
            int end = max(i, j);        
            if(group[start] == group[end]){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
    }
}
   
