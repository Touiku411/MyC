#include<iostream>
using namespace std;

long long A, Limit;
int Case = 0;
int fun(long long n) {
    int cnt = 1;
    while (n != 1) {
        
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        if (n > Limit)break;
        cnt++;
    }
    return cnt;
}

int main()
{
    
    while (cin >> A >> Limit) {
        if (A == -1 && Limit == -1)break;
        cout << "Case " << ++Case << ": A = " << A << ", limit = " << Limit << ", number of terms = " << fun(A) << endl;
    }
}

