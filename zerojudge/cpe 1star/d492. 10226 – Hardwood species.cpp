#include<iostream>
#include<map>
#include<string>
#include<iomanip>
using namespace std;
int main(){
    int T;cin>>T;
    cin.ignore();
    string temp;
    getline(cin,temp);
    while(T--){
        map<string, double> trees;
        string input;
        while(getline(cin,input) && !input.empty()){
            trees[input]++;
        }
        int sum = 0;
        for(auto i : trees){
            sum += i.second;
        }
        for(auto& i : trees){
            i.second = i.second / sum * 100;
        }
        for(auto i : trees){
            cout << i.first << " " << fixed << setprecision(4) << i.second << endl;
        }
    }
}
