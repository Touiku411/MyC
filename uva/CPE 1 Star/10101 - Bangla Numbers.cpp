#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

void bangla(long long n) {
	if (n >= 10000000) {
		bangla(n / 10000000);
		cout << " kuti";
		n %= 10000000;
	}
	if (n >= 100000) {
		bangla(n / 100000);
		cout << " lakh";
		n %= 100000;
	}
	if (n >= 1000) {
		bangla(n / 1000);
		cout << " hajar";
		n %= 1000;
	}
	if (n >= 100) {
		bangla(n / 100);
		cout << " shata";
		n %= 100;
	}
	if (n > 0) {
		cout << " " << n;
	}
}
int main() {
	/*cout << LLONG_MAX;*/
	long long n;
	int cnt = 1;
	while (cin >> n) {
		cout << setw(4) << right << cnt++ << ".";
		if (n == 0) 
			cout << " 0";
		else
			bangla(n);
		cout << endl;
	}
}
//'kuti' (10000000), 'lakh' (100000), 'hajar' (1000), 'shata' (100)
