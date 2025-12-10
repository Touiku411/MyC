#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

bool violate(vector<int>& vec, int m) {
    for (int i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] % m != 0)return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    while (cin >> n >> m) {
        if (m == 1 || m == 0) {
            cout << "Boring!\n";
            continue;
        }
        vector<int> vec;
        vec.push_back(n);
        int temp_n = n;
        while (temp_n > 1) {
            vec.push_back(temp_n / m);
            temp_n /= m;
        }
        if (!violate(vec, m)) {
            cout << vec[0];
            for (int i = 1; i < vec.size(); ++i) {
                cout << " " << vec[i];
            }
            cout << endl;
        }
        else
            cout << "Boring!\n";       
    }
    
}
    

