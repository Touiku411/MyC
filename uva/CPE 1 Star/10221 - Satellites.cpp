#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	const double pi = acos(-1.0);
	double s, a;
	string str;
	while (cin >> s >> a >> str) {
		double degree = -1;
		if (str == "deg")
			degree = a;
		else if (str == "min")
			degree = a / 60.0;
		if (degree > 180) {
			degree = 360 - degree;
		}
		double radian = degree * pi / 180;
		//弧長arc
		cout << fixed << setprecision(6) << (s + 6440) * radian << " ";
		//弦長chord
		cout << fixed << setprecision(6) << 2 * (s + 6440) * sin(radian / 2) << endl;
	}
}

