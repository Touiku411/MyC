#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n) {
		vector<pair<int, int>> factors;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				int cnt = 0;
				while (n % i == 0) {
					n /= i;
					cnt++;
				}
				factors.push_back({ i , cnt});
			}
		}
		if (n > 1) {
			factors.push_back({ n, 1 });
		}
		for (int i = 0; i < factors.size(); i++) {
			if (factors[i].second > 1) {
				cout << factors[i].first << "^" <<factors[i].second;
			}
			else {
				cout << factors[i].first;
			}
			if (i != factors.size() - 1) {
				cout << " * ";
			}
		}
		cout << "\n";
	}
	
}

