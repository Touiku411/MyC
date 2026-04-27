#include <iostream>
#include <stack>

using namespace std;

bool Valid(string &s){
    stack<char> stk;
    for(char c:s){
        if(c=='[')stk.push(']');
        else if(c=='(')stk.push(')');
        else{
            if(stk.empty() ||stk.top() != c){
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}
int main() {
    int T;cin >> T;
    cin.ignore();
    while(T--){
        string s;
        getline(cin, s);
        if(Valid(s)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    
}
