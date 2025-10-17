// Polynomial addition
#include <iostream>
#include <vector>
using namespace std;

void addition(const vector<long long int> &addendCoef,
			  const vector<long long int> &addendExpon, 
			  const vector<long long int> &adderCoef, 
			  const vector<long long int> &adderExpon, 
			  vector<long long int> &sumCoef,
			  vector<long long int> &sumExpon,int addendSize, int adderSize) {
	int i = 0, j = 0;
	
	while (i < addendSize && j < adderSize) {
		if (addendExpon[i] > adderExpon[j]) {
			sumCoef.push_back(addendCoef[i]);
			sumExpon.push_back(addendExpon[i]);
			i++;
		}
		else if(addendExpon[i] < adderExpon[j]) {
			sumCoef.push_back(adderCoef[j]);
			sumExpon.push_back(adderExpon[j]);
			j++;
		}
		else {
			if (addendCoef[i] + adderCoef[j] != 0) {
				sumCoef.push_back(addendCoef[i] + adderCoef[j]);
				sumExpon.push_back(addendExpon[i]);
			}
			i++;
			j++;
		}
	}
	while (i < addendSize) {
		sumCoef.push_back(addendCoef[i]);
		sumExpon.push_back(addendExpon[i]);
		i++;
	}
	while (j < adderSize) {
		sumCoef.push_back(adderCoef[j]);
		sumExpon.push_back(adderExpon[j]);
		j++;
	}
}

int main()
{
	int t; cin >> t;
	while (t--) {
		int addendSize;
		cin >> addendSize;
		vector<long long int> addendCoef(addendSize);
		vector<long long int> addendExpon(addendSize);
		
		
		for (int i = 0; i < addendSize; i++) {
			cin >> addendCoef[i];
		}
		for (int i = 0; i < addendSize; i++) {
			cin >> addendExpon[i];
		}
		int adderSize;
		cin >> adderSize;
		vector<long long int> adderCoef(adderSize);
		vector<long long int> adderExpon(adderSize);
		for (int i = 0; i < adderSize; i++) {
			cin >> adderCoef[i];
		}
		for (int i = 0; i < adderSize; i++) {
			cin >> adderExpon[i];
		}
		vector<long long int> sumCoef;
		vector<long long int> sumExpon;
		

		addition(addendCoef, addendExpon, adderCoef, adderExpon, sumCoef, sumExpon , addendSize, adderSize);
		
		int sumSize = sumCoef.size();

		cout << sumSize << endl;
		cout << sumCoef[0];
		for (int i = 1; i < sumSize; i++) {
			cout << " " << sumCoef[i];
		}
		cout << endl;
		cout << sumExpon[0];
		for (int i = 1; i < sumSize; i++) {
			cout << " " << sumExpon[i];
		}
		cout << endl;
	}
	
}



