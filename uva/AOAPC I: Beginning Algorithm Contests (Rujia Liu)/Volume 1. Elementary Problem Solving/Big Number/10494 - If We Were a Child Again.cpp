#include<iostream>
#include<string>
#include<vector>
#include<sstream> 

using namespace std;

int main()
{
	string input;
	while (getline(cin, input)) {
		stringstream ss(input);
		string n1, op, n2;
		ss >> n1 >> op >> n2;
		long long divisor = stoll(n2);
		string remainder_str , quotient_str;
		string dividend = n1;
		long long remainder = 0, quotient;
		bool Start = false;
		for (int i = 0; i < dividend.length(); ++i) {
			long long current = dividend[i] - '0';
			remainder = remainder * 10 + current;
			quotient = remainder / divisor;
			if (quotient > 0) {
				Start = true;
			}
			if (Start) {
				quotient_str += to_string(quotient);
			}
			remainder = remainder % divisor;
		}
		if (op == "/") {
			if (quotient_str.empty()) {
				cout << "0\n";
			}
			else {
				cout << quotient_str << endl;
			}
		}
		else if (op == "%") {
			cout << remainder << endl;
		}
	}
}



