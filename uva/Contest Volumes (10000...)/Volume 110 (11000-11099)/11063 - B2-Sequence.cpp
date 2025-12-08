#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool legal(vector<int> vec){
    for(int i = 1 ; i < vec.size();++i){
        if(vec[i - 1] >= vec[i]){
            return false;
        }
    }
    if (!vec.empty() && vec[0] <= 0) return false;
    return true;
}
int main()
{
	int T;
	int cnt = 1;
	while(cin >> T){

        vector<int> vec(T);
        for(int i =0;i<T;++i)
            cin >> vec[i];
        cout << "Case #" << cnt++ << ": ";

        map<int,int> Map;
        for(int i=0;i<T;++i){
            for(int j = i;j<T;++j){
                Map[vec[i] + vec[j]]++;
            }
        }
        bool correct = true;
        for(auto i :Map){
            if(i.second > 1){
                correct = false;
                break;
            }
        }
        if(correct && legal(vec)){
            cout << "It is a B2-Sequence.\n";
        }
        else{
            cout << "It is not a B2-Sequence.\n";
        }
        cout << endl;
	}
}
