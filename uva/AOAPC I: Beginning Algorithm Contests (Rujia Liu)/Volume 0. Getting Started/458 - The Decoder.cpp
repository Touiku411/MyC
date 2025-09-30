#include <iostream>

using namespace std;


int main()
{
	string input;
	while (cin >> input) {
		string out;
		for (char c : input) {
			c += '*' - '1';
			out += c;
		}
		cout << out << endl;
	}
	
}

