#include <iostream>
#include <ctime>
using namespace std;
const string Week[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
int main()
{
    int T;
    cin >> T;
    while (T--) {
        int M, D;
        cin >> M >> D;
        tm date = { 0 };
        date.tm_year = 2011 - 1900;
        date.tm_mon = M - 1;
        date.tm_mday = D;
        mktime(&date);
        cout << Week[date.tm_wday] << endl;
    }  
}
