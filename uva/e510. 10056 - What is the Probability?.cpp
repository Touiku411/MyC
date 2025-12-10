#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int S; cin >> S;
    while (S--) {
        int N, I;
        double P;
        cin >> N >> P >> I;
        double q = 1 - P;
        double a = pow(q, I - 1) * P;
        double r = pow(q, N);
        double result = a / (1.0 - r);
        cout <<  fixed << setprecision(4) << result << endl;
    }
}
    

