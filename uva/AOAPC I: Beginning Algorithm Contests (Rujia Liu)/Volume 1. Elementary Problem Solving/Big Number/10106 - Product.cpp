#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

void multi(vector<int>& multiplicand, vector<int>& multiplier, vector<int>& product) {
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

}
int main()
{
	string line1;
	string line2;
	while (getline(cin, line1) && getline(cin,line2)) {
		vector<int> multiplicand(line1.length());
		vector<int> multiplier(line2.length());
		for (int i = 0; i < line1.size(); ++i) {
			multiplicand[i] = line1[line1.length() - 1 - i] - '0';
		}
		for (int i = 0; i < line2.size(); ++i) {
			multiplier[i] = line2[line2.length() - 1 - i] - '0';
		}
		vector<int> product(multiplicand.size() + multiplier.size());
		multi(multiplicand, multiplier, product);
		for (int i = product.size() - 1; i >= 0; --i) {
			cout << product[i];
		}
		cout << endl;
	}

} 


