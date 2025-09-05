#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input; getline(cin,input);
	int k = '*' - '1';
	string ans;
	for (char c : input) {
		c += k;
		ans += c;
	}
	cout << ans <<"\n";
}

