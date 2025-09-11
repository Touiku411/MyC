#include <iostream>
#include <numeric>
#include <algorithm> // __gcd(a,b) C++14
using namespace std;

int main()
{
	int x1, y1, x2, y2;
	while (cin >> x1 >> y1 >> x2 >> y2) {
		int dx = x2 - x1;
		int dy = y2 - y1;
		int fenmu = dx * dx;

		int g = gcd(dy, fenmu);
		int b = dy / g;
		int a = fenmu / g;
		int c = -2 * b * x1;
		int d = b * x1 * x1 + y1 * a;

		int G = gcd(gcd(a, abs(b)),gcd(abs(c), abs(d)));
		a /= G; b /= G; c /= G; d /= G;
		cout << a << "y = " << b << "x^2 + " << c << "x + " << d << "\n";
	}
}

