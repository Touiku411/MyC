#include<iostream>
#include<vector>
using namespace std;

void addition(vector<long long int>& addendCoef, vector<long long int>& addendExpon, int& addendSize,
	vector<long long int>adderCoef, vector<long long int>adderExpon, int adderSize) {
	vector<long long int>tempCoef;
	vector<long long int>tempExpon;
	int tempSize = 0;
	int i = 0, j = 0;
	while (i < addendSize && j < adderSize) {
		if (addendExpon[i] > adderExpon[j]) {
			tempCoef.push_back(addendCoef[i]);
			tempExpon.push_back(addendExpon[i]);
			i++;
		}
		else if (addendExpon[i] < adderExpon[j]) {
			tempCoef.push_back(adderCoef[j]);
			tempExpon.push_back(adderExpon[j]);
			j++;
		}
		else {
			long long int sum = addendCoef[i] + adderCoef[j];
			if (sum != 0) {
				tempCoef.push_back(addendCoef[i] + adderCoef[j]);
				tempExpon.push_back(addendExpon[i]);
			}
			i++;
			j++;
		}
	}
	while (i < addendSize) {
		tempCoef.push_back(addendCoef[i]);
		tempExpon.push_back(addendExpon[i]);
		i++;
	}
	while (j < adderSize) {
		tempCoef.push_back(adderCoef[j]);
		tempExpon.push_back(adderExpon[j]);
		j++;
	}
	tempSize = tempCoef.size();
	addendCoef = tempCoef;
	addendExpon = tempExpon;
	addendSize = tempSize;
}

void multiplication(vector<long long int> multiplicandCoef, vector<long long int> multiplicandExpon, int multiplicandSize,
	vector<long long int> multiplierCoef, vector<long long int> multiplierExpon, int multiplierSize,
	vector<long long int>& productCoef, vector<long long int>& productExpon, int& productSize)
{
	for (int i = 0; i < multiplicandSize; i++) {
		vector<long long int>tempCoef;
		vector<long long int>tempExpon;
		int tempSize = 0;
		for (int j = 0; j < multiplierSize; j++) {
			tempCoef.push_back(multiplicandCoef[i] * multiplierCoef[j]);
			tempExpon.push_back(multiplicandExpon[i] + multiplierExpon[j]);
			tempSize++;
		}
		if (i == 0) {
			for (int k = 0; k < tempSize; k++) {
				productCoef.push_back(tempCoef[k]);
				productExpon.push_back(tempExpon[k]);
			}
			productSize = tempSize;
		}
		else {
			addition(productCoef, productExpon, productSize, tempCoef, tempExpon, tempSize);
		}
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		int multiplicandSize;
		cin >> multiplicandSize;
		vector<long long int> multiplicandCoef(multiplicandSize);
		vector<long long int> multiplicandExpon(multiplicandSize);
		for (int i = 0; i < multiplicandSize; i++) {
			cin >> multiplicandCoef[i];
		}
		for (int i = 0; i < multiplicandSize; i++) {
			cin >> multiplicandExpon[i];
		}
		int multiplierSize;
		cin >> multiplierSize;
		vector<long long int> multiplierCoef(multiplierSize);
		vector<long long int> multiplierExpon(multiplierSize);
		for (int i = 0; i < multiplierSize; i++) {
			cin >> multiplierCoef[i];
		}
		for (int i = 0; i < multiplierSize; i++) {
			cin >> multiplierExpon[i];
		}

		vector<long long int> productCoef;
		vector<long long int> productExpon;
		int productSize = 0;

		multiplication(multiplicandCoef, multiplicandExpon, multiplicandSize,
			multiplierCoef, multiplierExpon, multiplierSize, productCoef, productExpon, productSize);

		cout << productSize << endl;
		cout << productCoef[0];
		for (int i = 1; i < productSize; i++) {
			cout << " " << productCoef[i];
		}
		cout << endl;
		cout << productExpon[0];
		for (int i = 1; i < productSize; i++) {
			cout << " " << productExpon[i];
		}
		cout << endl;
	}
}
