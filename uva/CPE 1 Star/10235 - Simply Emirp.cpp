#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
//emirp 是質數反過來也是
bool isPrime(int n) {
    if (n < 2)return false;
    if (n == 2)return true;
    if (n % 2 == 0)return false;
    for (int i = 3; i <= sqrt(n); i+=2) {
        if (n % i == 0)return false;
    }
    return true;
}
int main()
{
    int N;
    while (cin >> N) {     
        if (!isPrime(N)) {
            cout << N << " is not prime.\n";
        }
        else {
            string rev = to_string(N);
            reverse(rev.begin(), rev.end());
            int rev_n = stoi(rev);
            if (isPrime(rev_n) && N != rev_n) {
                cout << N << " is emirp.\n";
            }
            else {
                cout << N << " is prime.\n";
            }
        }       
    }
    
}

