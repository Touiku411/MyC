#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;

bool isB2(vector<int>& vec) {
	set<int> s;
	for (int i = 0; i < vec.size(); ++i) {
		for (int j = i; j < vec.size(); ++j) {
			int digit = vec[i] + vec[j];
			if (s.find(digit) != s.end())
				return false;
			else
				s.insert(digit);
		}
	}
	return true;
}
int main() {
	int N;
	int cnt = 1;
	while (cin >> N) {
		vector<int> vec;
		bool isValid = true;
		for (int i = 0; i < N; ++i) {
			int x; cin >> x;
			if (x < 1) {
				isValid = false;
			}
			vec.push_back(x);
		}
		if (isValid) {
			for (int i = 0; i < N - 1; ++i) {
				if (vec[i] >= vec[i + 1]) {
					isValid = false;
					break;
				}
			}
		}
		cout << "Case #" << cnt++ << ": ";
		if (isValid && isB2(vec)) {
			cout << "It is a B2-Sequence.\n";
		}
		else {
			cout << "It is not a B2-Sequence.\n";
		}
		cout << endl;
	}
}

