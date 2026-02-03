#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T; cin >> T;
    while (T--) {
        int s, d; cin >> s >> d;
        int x = -1, y = -1;
        x = (s + d) / 2;
        y = s - x;
        if (x < 0 || y < 0 || (s + d) % 2 != 0) {
            cout << "impossible\n";
        }
        else {
            cout << x << " " << y << endl;
        }
    }
}

