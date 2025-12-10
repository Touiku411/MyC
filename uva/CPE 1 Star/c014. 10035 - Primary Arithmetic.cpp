#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int addition(vector<int> a, vector<int> b) {
    int carry = 0;
	int count = 0;
	int i = 0;
	while (i < a.size() || i < b.size()) {
		int val1 = (i < a.size()) ? a[i] : 0;
		int val2 = (i < b.size()) ? b[i] : 0;
		int sum = val1 + val2 + carry;
		if (sum > 9) {
			carry = 1;
			count++;
		}
		else {
			carry = 0;
		}
		i++;
	}
	return count;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
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
    
