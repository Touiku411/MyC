#include<iostream>
#include<vector>
#include<string>
using namespace std;

int answer[1005];
void multi(vector<int>& a, int x) {
	int carry = 0;
	for (int i = 0; i < a.size(); ++i) {
		int product = a[i] * x + carry;
		a[i] = product % 10;
		carry = product / 10;
	}
	while (carry) {
		a.push_back(carry % 10);
		carry /= 10;
	}
}
int sumDigits(const vector<int>& v) {
	int sum = 0;
	for (int digit : v) {
		sum += digit;
	}
	return sum;
}
void precompute() {
	vector<int> v;
	v.push_back(1);
	answer[0] = 0;
	answer[1] = 1;
	for (int i = 2; i <= 1000; ++i) {
		multi(v, i);
		answer[i] = sumDigits(v);
	}
}
int main() {
	precompute();
	int n;
	while (cin >> n) {
		cout << answer[n] << endl;
	}
	return 0;
}
