#include <iostream>
#include <string>
using namespace std;

int GCD(int a, int b) {
	if (b == 0) return a;
	return GCD(b, a % b);
}
int main() {
	int T;
	cin >> T;
	int cnt = 1;
	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;
		int val1 = stoi(s1, nullptr, 2);
		int val2 = stoi(s2, nullptr, 2);
		cout << "Pair #" << cnt++ << ": ";
		if (GCD(val1, val2) != 1) {
			cout << "All you need is love!\n";
		}
		else {
			cout << "Love is not all you need!\n";
		}
	}
	
}
