#include<iostream>
#include<vector>

using namespace std;
void subtraction(vector<int>& minuendCoef, vector<long long int>& minuendExpon, int& minuendSize,
	vector<int> subtrahendCoef, vector<long long int> subtrahendExpon, int subtrahendSize) {

	vector<int> tempCoef;
	vector<long long int> tempExpon;
	int i = 0, j = 0;
	while (i < minuendSize && j < subtrahendSize) {
		if (minuendExpon[i] < subtrahendExpon[j]) {
			tempCoef.push_back(-subtrahendCoef[j]);
			tempExpon.push_back(subtrahendExpon[j]);
			j++;
		}
		else if (minuendExpon[i] > subtrahendExpon[j]) {
			tempCoef.push_back(minuendCoef[i]);
			tempExpon.push_back(minuendExpon[i]);
			i++;
		}
		else {
			int diff = minuendCoef[i] - subtrahendCoef[j];
			if (diff != 0) {
				tempCoef.push_back(diff);
				tempExpon.push_back(minuendExpon[i]);
			}
			i++; j++;
		}

	}
	while (i < minuendSize) {
		tempCoef.push_back(minuendCoef[i]);
		tempExpon.push_back(minuendExpon[i]);
		i++;
	}
	while (j < subtrahendSize) {
		tempCoef.push_back(- subtrahendCoef[j]);
		tempExpon.push_back(subtrahendExpon[j]);
		j++;
	}

	minuendSize = tempCoef.size();
	for (int i = 0; i < minuendSize; i++) {
		minuendCoef[i] = tempCoef[i];
		minuendExpon[i] = tempExpon[i];
	}


}
void division(vector<int> dividendCoef, vector<long long int> dividendExpon, int dividendSize, 
			vector<int> divisorCoef, vector<long long int> divisorExpon, int divisorSize,
		vector<int>& quotientCoef,vector<long long int>& quotientExpon, int &quotientSize,
	vector<int> &remainderCoef, vector<long long int> &remainderExpon, int &remainderSize) {

	for (int i = 0; i < dividendSize; i++) {
		remainderCoef[i] = dividendCoef[i];
		remainderExpon[i] = dividendExpon[i];
	}
	remainderSize = dividendSize;

	while (remainderSize > 0 && remainderExpon[0] >= divisorExpon[0]) {
		int coef = remainderCoef[0] / divisorCoef[0];
		long long int exp = remainderExpon[0] - divisorExpon[0];

		quotientCoef.push_back(coef);
		quotientExpon.push_back(exp);
		quotientSize++;

		vector<int> tempCoef;
		vector<long long int> tempExpon;
		int tempSize = 0;

		for (int i = 0; i < divisorSize; i++) {
			tempCoef.push_back(coef * divisorCoef[i]);
			tempExpon.push_back(exp + divisorExpon[i]);
		}
		tempSize = tempCoef.size();
		subtraction(remainderCoef, remainderExpon, remainderSize, tempCoef, tempExpon, tempSize);

	}

	if (remainderSize == 0) {
		remainderSize = 1;
		remainderCoef[0] = 0;
		remainderExpon[0] = 0;
	}

}
void output(vector<int> coefficient, vector<long long int>exponent, int size) {
	cout << size << endl;
	cout << coefficient[0];
	for (int i = 1; i < size; i++)
		cout << " " << coefficient[i];
	cout << endl;
	cout << exponent[0];
	for (int i = 1; i < size; i++)
		cout << " " << exponent[i];
	cout << endl;
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		int dividendSize;
		cin >> dividendSize;
		vector<int> dividendCoef(dividendSize);
		vector<long long int>dividendExpon(dividendSize);
		for (int i = 0; i < dividendSize; i++) {
			cin >> dividendCoef[i];
		}
		for (int i = 0; i < dividendSize; i++) {
			cin >> dividendExpon[i];
		}
		int divisorSize;
		cin >> divisorSize;
		vector<int> divisorCoef(divisorSize);
		vector<long long int> divisorExpon(divisorSize);
		for (int i = 0; i < divisorSize; i++) {
			cin >> divisorCoef[i];
		}
		for (int i = 0; i < divisorSize; i++) {
			cin >> divisorExpon[i];
		}
		vector<int>quotientCoef;
		vector<long long int>quotientExpon;
		int quotientSize = 0;

		int remainderSize = dividendSize;
		vector<int>remainderCoef(remainderSize);
		vector<long long int>remainderExpon(remainderSize);
		
		division(dividendCoef, dividendExpon, dividendSize,
			divisorCoef, divisorExpon, divisorSize,
			quotientCoef, quotientExpon, quotientSize,
			remainderCoef, remainderExpon, remainderSize);

		output(quotientCoef, quotientExpon, quotientSize);
		output(remainderCoef, remainderExpon, remainderSize);
	}
}
