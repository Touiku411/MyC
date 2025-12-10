#include<iostream>
#include<map>
#include<string>
#include<iomanip>
using namespace std;
char load(char c){
    map<char,char> Map;
    Map['2'] = '`';
    Map['3'] = '1';
    Map['e'] = 'q';
    Map['d'] = 'a';
    Map['c'] = 'z';
    Map['4'] = '2';
    Map['r'] = 'w';
    Map['f'] = 's';
    Map['v'] = 'x';
    Map['5'] = '3';
    Map['t'] = 'e';
    Map['g'] = 'd';
    Map['b'] = 'c';
    Map['6'] = '4';
    Map['y'] = 'r';
    Map['h'] = 'f';
    Map['n'] = 'v';
    Map['7'] = '5';
    Map['u'] = 't';
    Map['j'] = 'g';
    Map['m'] = 'b';
    Map['8'] = '6';
    Map['i'] = 'y';
    Map['k'] = 'h';
    Map[','] = 'n';
    Map['9'] = '7';
    Map['o'] = 'u';
    Map['l'] = 'j';
    Map['.'] = 'm';
    Map['0'] = '8';
    Map['p'] = 'i';
    Map[';'] = 'k';
    Map['/'] = ',';
    Map['-'] = '9';
    Map['['] = 'o';
    Map['\''] = 'l';
    Map['='] = '0';
    Map[']'] = 'p';
    Map['\\'] = '[';
    auto it = Map.find(c);
    if(it != Map.end()){
        return Map[c];
    }
    else{
        return c;
    }

}
int main(){
    string input;
    while(getline(cin,input)){
        for(char c : input){
            cout << load(c);
        }
        cout << endl;
    }
}
