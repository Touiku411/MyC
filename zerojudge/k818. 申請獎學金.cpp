#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int highest = max(a, max(b, c));
	int lowest = min(a, min(b, c));
	int average = (a + b + c) / 3;
	bool pass = true;
	if (highest < 90 || average < 60 || lowest < 40) pass = false;

	cout << (pass ? "Y" : "N");
}

