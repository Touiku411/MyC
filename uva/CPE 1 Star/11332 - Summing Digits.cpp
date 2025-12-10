#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    while(cin >> input && input != "0"){
        while(input.size() > 1){
            int sum = 0;
            for(int i = 0; i< input.size() ;++i){
                sum += input[i] - '0';
            }
            input = to_string(sum);
        }
        cout << input << endl;
    }
}
