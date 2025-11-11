#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

void multi(vector<int>& multiplicand, vector<int>& multiplier) {
	vector<int> product(multiplicand.size() + multiplier.size());
	for (int i = 0; i < multiplier.size(); ++i) {
		for (int j = 0; j < multiplicand.size(); ++j) {
			product[i + j] += multiplier[i] * multiplicand[j];
		}
	}
	for (int i = 0; i < product.size() - 1; ++i) {
		if (product[i] > 9) {
			product[i + 1] += product[i] / 10;
			product[i] = product[i] % 10;
		}
	}
	while (product.size() > 1 && product.back() == 0) {
		product.pop_back();
	}
	multiplicand = product;
}
int main()
{
	string input;
	while (getline(cin, input)) {
		string R = input.substr(0, 6);
		int n = stoi(input.substr(7, 2));
		if (n == 0) {
			cout << "0\n";
			continue;
		}
		while (R.size() > 1 && R.back() == '0') {
			R.pop_back();
		}
		int dotpos = R.find('.');
		dotpos = R.length() - dotpos - 1;
		dotpos *= n;
		vector<int> num;
		for (int i = 0; i < R.size(); ++i) {
			if (R[R.length() - 1 - i] != '.') {
				num.push_back(R[R.length() - 1 - i] - '0');
			}
		}
		vector<int> product;
		product = num;
		while (n > 1) {
			multi(product, num);
			n--;
		}
		if (dotpos > product.size()) {
			cout << ".";
			while (dotpos > product.size()) {
				cout << "0";
				dotpos--;
			}
		}
		for (int i = product.size() - 1; i >= 0; --i) {
			cout <<  product[i];
			if (i == dotpos) {
				cout << ".";
			}
		}
	
		cout << endl;
	}

} 


