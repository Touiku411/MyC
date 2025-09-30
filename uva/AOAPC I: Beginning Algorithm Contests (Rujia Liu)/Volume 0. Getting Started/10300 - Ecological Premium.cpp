#include <iostream>

using namespace std;


int main()
{
	int n; cin >> n;
	while (n--) {
		int x; cin >> x;
		long long money = 0;
		while (x--) {
			long long a, b, c;
			cin >> a >> b >> c;
			money+= a * c ; // a / b * c * b
		}
		cout << money << endl;
	}
}

