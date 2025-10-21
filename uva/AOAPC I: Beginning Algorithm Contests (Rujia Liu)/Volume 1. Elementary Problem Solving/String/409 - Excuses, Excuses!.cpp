#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t1, t2;
	int ncase = 1;
	while (cin >> t1 >> t2) {
		vector<string> Keyword(t1);
		vector<string> Excuse(t2);
		vector<string> temp(t2);
		vector<pair<int, int>> vec;
		for (int i = 0; i < t1; i++) {
			cin >> Keyword[i];
		}
		cin.ignore();
		for (int i = 0; i < t2; i++) {
			getline(cin, Excuse[i]);
		}
		temp = Excuse;
		for (int i = 0; i < t2; i++) {
			for (char& c : temp[i]) {
				if (isalpha(c))
					c = tolower(c);
				else
					c = ' ';
			}
		}
		int Max = 0;
		for (int i = 0; i < t2; i++) {
			int cnt = 0;
			stringstream ss(temp[i]);
			string word;
			while (ss >> word) {
				for (const string& k : Keyword) {
					if (word == k) {
						cnt++;
					}
				}
			}
			Max = max(cnt, Max);
			vec.push_back({ i, cnt });
		}
		cout << "Excuse Set #" << ncase++ << '\n';
		for (auto& i : vec) {
			if (i.second == Max)
				cout << Excuse[i.first] << "\n";
		}
		cout << '\n';
		vec.clear();
	}
}

