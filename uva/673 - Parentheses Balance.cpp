#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

bool SpaceOrempty(string s) {
	for (char c : s) {
		if (!isspace(c)) {
			return false;
		}
	}
	return true;
}

int main() {
	int T; cin >> T;
	cin.ignore();
	while (T--) {
		string input;
		getline(cin, input);
		if (SpaceOrempty(input)) {
			cout << "Yes\n";
			continue;
		}
		stack<char> stk;
		for (int i = 0; i < input.size(); i++) {
			char c = input[i];
			if (c == ')') {
				if (!stk.empty() && stk.top() == '(') {
					stk.pop();
					continue;
				}
			}
			else if (c == ']') {
				if (!stk.empty() && stk.top() == '[') {
					stk.pop();
					continue;
				}
			}
			stk.push(c);
		}
		cout << (stk.empty() ? "Yes\n" : "No\n");
	}

}
