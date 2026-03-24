#include <iostream>
#include <string>
#include <set>
//#include <algorithm>
using namespace std;

int main() {
    int T;
    while(cin >> T && T != 0){
        multiset<int> boxes;
        long long ans = 0;
        while(T--){   
            int n; cin >>n;
            for(int i =0;i<n;++i){
                int x;cin>>x;
                boxes.insert(x);
            } 
            //sort(boxes.begin(),boxes.end());
            //退一行
            //auto it = prev(boxes.end(),1);      
            auto it_max = --boxes.end();
            auto it_min = boxes.begin();
            ans += *it_max - *it_min;
            boxes.erase(it_max);
            boxes.erase(it_min);
        }
        cout << ans << endl;
    }
}

