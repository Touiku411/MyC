#include <iostream>
using namespace std;

int main()
{
    long long s, d;
    while (cin >> s >> d) {
        long long cur_day = 0;
       
        while (true) {
            cur_day += s;
            if (cur_day >= d) {
                cout << s << endl;
                break;
            }
            s++;
        }
    }
    
}

