#include<iostream>
#include<vector>
using namespace std;

int addition(vector<int> a, vector<int> b) {
	int carry = 0;
	int sumSize = (a.size() > b.size()) ? a.size() : b.size();
	vector<int> sum(sumSize + 1);
	for (int i = 0; i < a.size(); ++i) {
		sum[i] = a[i];
	}
	for (int i = 0; i < b.size(); ++i) {
		sum[i] += b[i];
	}
	for (int i = 0; i < sum.size() - 1; ++i){
		if (sum[i] > 9) {
			sum[i + 1] += 1;
			sum[i] -= 10;
			carry++;
		}
	}
	return carry;
}
int main() {
	string input1, input2;
	while (cin >> input1 >> input2) {
		if (input1 == "0" && input2 == "0")break;
		vector<int> num1(input1.size());
		vector<int> num2(input2.size());
		for (int i = 0; i < input1.size(); ++i) {
			num1[i] = input1[input1.size() - i - 1] - '0';
		}
		for (int i = 0; i < input2.size(); ++i) {
			num2[i] = input2[input2.size() - i - 1] - '0';
		}
		int carry = addition(num1, num2);
		if (carry == 0) {
			cout << "No carry operation.\n";
		}
		else if (carry == 1) {
			cout << carry << " carry operation.\n";
		}
		else {
			cout << carry << " carry operations.\n";
		}
	}
	
}
