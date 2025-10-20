#include<iostream>
#include<string>
using namespace std;

char toAscii(string &s) {
	int len = 8;
	int dec = 0;
	int k = 1;
	for (int i = len - 1; i >= 0; i--) {
		dec += (s[i] - '0') * k;
		k *= 2;
	}
	return static_cast<char>(dec);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	while (getline(cin, input)) {
		if (input == "___________")continue;
		string binary;
		for (char c : input) {
			if (c == 'o')
				binary += '1';
			else if (c == ' ')
				binary += '0';
		}
		cout << toAscii(binary);
	}
}

//___________
//| o   .  o|
//|  o  .   |
//| ooo .  o|
//| ooo .o o|
//| oo o.  o|
//| oo  . oo|
//___________
