#include <iostream>
#include <numeric>

using namespace std;


int main()
{
	int i,j; 
	while (cin >> i >> j) {
		cout << i << " " << j << " ";
		if (i > j) {
			swap(i, j);
		}	
		int max = 0;
		for (int k = i; k <= j; k++) {
			int n = k;
			int cyclelen = 1;
			while (n != 1) {
				if (n % 2 != 0) {
					n = 3 * n + 1;
				}
				else
					n /= 2;
				cyclelen++;
			}
			if (cyclelen > max)
				max = cyclelen;
		}
		cout << max << "\n";

	}
}

