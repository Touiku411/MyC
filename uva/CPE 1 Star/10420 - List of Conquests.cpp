#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    map<string,int> Map;
    while(N--){
        string line;
        getline(cin,line);
        stringstream ss(line);
        string cty;
        ss >> cty;
        Map[cty]++;
    }
    for(auto i : Map){
        cout << i.first << " " << i.second << endl;
    }
}
