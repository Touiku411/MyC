#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c; cin >> a >> b >> c;
	int r = b * b - 4 * a * c;
	int x1 = (-b + sqrt(r)) / (2 * a);
	int x2 = (-b - sqrt(r)) / (2 * a);
	if (r == 0) {
		cout << "Two same roots x=" << x1 <<"\n";
	}
	else if (r > 0) {
		cout << "Two different roots x1=" << x1 << " , x2=" << x2 << "\n";
	}
	else {
		cout << "No real root\n";
	}
}

