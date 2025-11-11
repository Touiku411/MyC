#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

void addition(vector<int>& addend, vector<int>& adder) {
	int sumSize = max(addend.size(), adder.size());
	vector<int> sum(sumSize + 1);
	for (int i = 0; i < addend.size(); ++i) {
		sum[i] = addend[i];
	}
	for (int i = 0; i < adder.size(); ++i) {
		sum[i] += adder[i];
	}
	for (int i = 0; i < sum.size() - 1; ++i) {
		if (sum[i] > 9) {
			sum[i + 1] += 1;
			sum[i] -= 10;
		}
	}
	while (sum.size() > 1 && sum.back() == 0) {
		sum.pop_back();
	}
	addend = sum;
}
int main()
{
	string line;
	vector<int> sum(0, 0);
	while (getline(cin, line) && line != "0") {
		vector<int> addend(line.length());
		for (int i = 0; i < addend.size(); ++i) {
			addend[i] = line[line.length() - 1 - i] - '0';
		}
		addition(sum,addend);
	}
	for (int i = sum.size() - 1; i >= 0; --i) {
		cout << sum[i];
	}
	cout << endl;
} 


