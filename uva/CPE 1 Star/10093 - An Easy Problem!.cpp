#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
            // 10 
//(0..9 and A..Z and a..z)
int charToValue(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	else if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 10;
	}
	else if (c >= 'a' && c <= 'z') {
		return c - 'a' + 36;
	}
	return 0;
}
int main()
{

	string n;
	while (cin >> n) {
		int sum = 0;
		int Max = 1;
		for (char c : n) {
			int digit = charToValue(c);
			Max = max(Max, digit);
			sum += digit;
		}
		bool found = false;
		int N = Max + 1;
		for (int i = N; i <= 62; ++i) {
			if (sum % (i - 1) == 0) {
				found = true;
				cout << i << endl;
				break;
			}
		}
		if (!found) {
			cout << "such number is impossible!\n";
		}
	}
}

