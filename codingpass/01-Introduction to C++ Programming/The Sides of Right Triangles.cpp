#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int side1, side2, side3;
	cin >> side1 >> side2 >> side3;
	int s[3] = { side1,side2,side3 };
	sort(s, s + 3);
	cout << (s[0] > 0 && s[0] * s[0] + s[1] * s[1] == s[2] * s[2] ? "These integers form a right triangle\n" : "These integers do not form a right triangle\n");

}
