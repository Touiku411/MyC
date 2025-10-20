#include<iostream>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	cin.ignore();
	while (T--) {
		string input1, input2;
		getline(cin, input1);
		getline(cin, input2);

		int p1 = input1.find('<');
		int p2 = input1.find('>');
		int p3 = input1.find('<', p2);
		int p4 = input1.find('>', p3);

		string s1, s2, s3, s4, s5;

		s1 = input1.substr(0, p1);
		s2 = input1.substr(p1 + 1, p2 - p1 - 1);
		s3 = input1.substr(p2 + 1, p3 - p2 - 1);
		s4 = input1.substr(p3 + 1, p4 - p3 - 1);
		s5 = input1.substr(p4 + 1);
		cout << s1 << s2 << s3 << s4 << s5 << '\n';
		
		int p = input2.find("...");
		cout << input2.substr(0, p) << s4 << s3 << s2 << s5 << '\n';
	}
}
