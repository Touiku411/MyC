#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string input;
	vector<string> code;
	bool t = true;
	int cnt = 0;
	while (cin >> input) {
		if (input == "9") {
			cout << "Set " << ++cnt;
			if (t)
				cout << " is immediately decodable\n";
			else
				cout << " is not immediately decodable\n";
			t = true;
			code.clear();
			continue;
		}
		for (auto &i : code) {
			if (input.rfind(i, 0) == 0 || i.rfind(input, 0) == 0){
				t = false;
				break;
			}
		}
		code.push_back(input);
	}
}

