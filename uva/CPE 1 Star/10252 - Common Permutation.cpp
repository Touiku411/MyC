#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string s1, s2;
    while(getline(cin,s1) && getline(cin,s2)){
        map<char,int> count1;
        map<char,int> count2;
        for(char c : s1){
            count1[c]++;
        }
        for(char c : s2){
            count2[c]++;
        }
   
        for(auto i : count1){
        auto it = count2.find(i.first);
            if(it != count2.end()){
                int min_count = min(i.second, it->second);
                while(min_count--)
                    cout << i.first;
            }
        }
        cout << endl;

    }
}
