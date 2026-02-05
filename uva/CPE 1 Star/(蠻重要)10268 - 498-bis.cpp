#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
using ll = long long;
int main()
{
    ll x;
    while (cin >> x) {
        string line;
        getline(cin >> ws, line);
        stringstream ss(line);
        ll num;
        vector<ll> xishu;
        while (ss >> num) {
            xishu.push_back(num);
        }
        ll result = 0;
        int n = xishu.size() - 1;
        for (int i = 0; i < xishu.size() - 1; ++i) {
            result = result * x + xishu[i] * n;
            n--;
        }
        cout << result << endl;
    }
}

