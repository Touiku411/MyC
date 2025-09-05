#include <iostream>
using namespace std;

string fun(int x) {
    if (x == 0) {
        return "普通";
    }
    else if (x == 1) {
        return "吉";
    }
    else if (x == 2) {
        return "大吉";
    }
}
int main()
{
    int M, D, S; cin >> M >> D;
    S = (M * 2 + D) % 3;
    cout << fun(S) << "\n";
}

