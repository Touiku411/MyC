#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_PRIME = 32000;
vector<int> primes;

void sieve() {
    vector<bool> is_Prime(MAX_PRIME, true);
    is_Prime[0] = is_Prime[1] = false;
    for (int i = 2; i < MAX_PRIME; i++) {
        if (is_Prime[i]) {
            primes.push_back(i);
        }
        for (long long j = (long long)i * i; j < MAX_PRIME; j += i) {
            is_Prime[j] = false;
        }
    }
}
int divisor_count(long long n) {
    int cnt = 1;
    for (int p : primes) {
        if ((long long)p * p > n)break;
        int exp = 0;//次方
        while (n % p == 0) {
            n /= p;
            exp++;
        }
        cnt *= (exp + 1);
    }
    if (n > 1)cnt *= 2;
    return cnt;
}

int main() {
    sieve();
    int n; cin >> n;
    while (n--) {
       
        long long L, U; cin >> L >> U;
        int max = 0;
        long long best_num = L;
        for (long long i = L; i <= U; i++) {
            int d = divisor_count(i);
            if (d > max) {
                max = d;
                best_num = i;
            }
        }

        cout << "Between " << L << " and " << U << ", "
            << best_num << " has a maximum of " << max << " divisors.\n";
    }
    return 0;
}
