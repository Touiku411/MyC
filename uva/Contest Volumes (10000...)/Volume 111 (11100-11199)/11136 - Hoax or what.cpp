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


//不用mutiset解法
//highest,lowest可選
#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
using namespace std;
vector<int> vec(1000001);
int highest = 1000001;
int lowest = 0;
int findmax(){
    for(int i = highest ; i >= 0;--i){
        if(vec[i] > 0){
            vec[i]--;
            highest = i;
            return i;
        }
    }
    return -1;
}
int findmin(){
     for(int i = lowest; i < 1000001; ++i){
        if(vec[i] > 0){
            vec[i]--;
            lowest = i;
            return i;
        }
    }
    return -1;
}
int main() {
    int T;
    while(cin >> T && T != 0){
        long long ans = 0;
        highest = 0;
        lowest = 0;
        while(T--){   
            int n; cin >>n;
            for(int i =0;i<n;++i){
                int x;cin>>x;
                vec[x]++;
                if( x > highest) highest = x;
                if( x < lowest) lowest = x;
            }     
            int  max = findmax();
            int  min = findmin();
            ans += max - min;
        }
        for(int i = 0; i<=1000000;++i){
            vec[i] = 0;
        }
        cout << ans << endl;
    }
}


