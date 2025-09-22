#include <iostream>
#include <cmath>
using namespace::std;

bool haveCommonFactors(int a, int b)
{
	int m = min(a, b);
	for (int i = 2; i <= m; i++)
		if (a % i == 0 && b % i == 0)
			return true;

	return false;

}

int main()
{
	int numCases;
	cin >> numCases;
	for (int i = 1; i <= numCases; i++)
	{
		int a, b;
		cin >> a >> b;

		if (haveCommonFactors(a, b))
			cout << "not coprime" << endl;
		else
			cout << "coprime" << endl;
	}
}

