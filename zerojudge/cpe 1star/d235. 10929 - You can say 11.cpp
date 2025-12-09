#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

int returnSum(vector<int>& vec){
    int sum = 0;
    for(int i : vec){
        sum += i;
    }
    return sum;
}
int main(){
    string input;
    while(getline(cin,input) && input != "0"){
        vector<int> odds;
        vector<int> evens;
        for(int i = input.size() - 1; i>=0;--i){
            if(i%2 == 0)
                odds.push_back(input[i] - '0');
            else
                evens.push_back(input[i] - '0');
        }
        int odds_sum = returnSum(odds), evens_sum  = returnSum(evens);
        if((odds_sum - evens_sum) % 11 == 0){
            cout << input << " is a multiple of 11.\n";
        }
        else{
            cout << input << " is not a multiple of 11.\n";
        }
    }
}
