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
// 2
#include <iostream>
#include <ctime>
using namespace std;
const string Week[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main()
{
    int T;
    cin >> T;
    while (T--) {
        int M, D;
        cin >> M >> D;
        int currentDay = 6;//2011/1/1 is Saturday
        for (int i = 1; i < M; ++i) {
            currentDay += daysInMonth[i];
        }
        currentDay += D - 1;
        cout << Week[currentDay % 7] << endl;
    }  
}
