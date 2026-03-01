#include <iostream>
using namespace std;
long long getSteps(long long x, long long y) {
	long long s = x + y;
	return ((s + 1) * s) / 2 + x;
}
int main()
{
	int cnt = 1;
	int T; cin >> T;
	while (T--) {
		long long x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << "Case " << cnt++ << ": " << getSteps(x2, y2) - getSteps(x1, y1) << endl;
	}
}

