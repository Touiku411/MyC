#include <iostream>
#include <numeric>

using namespace std;

int fill(int n, int m) {
	if (n == 0 || m == 0)return 0;
	int k = 1;
	while ((k * 2 <= m) && (k * 2 <= n))k *= 2;
	return 1 + fill( k, m - k) + fill(n - k, m);

}
int main()
{
	int n, m; cin >> n >> m;
	cout<< fill(n, m);

}

