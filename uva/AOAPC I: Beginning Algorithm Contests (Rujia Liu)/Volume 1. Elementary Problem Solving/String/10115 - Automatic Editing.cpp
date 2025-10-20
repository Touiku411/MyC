#include<iostream>
#include<string>
#include<vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	while (cin >> T) {
		if (T == 0)break;
		cin.ignore();
		vector<pair<string, string>> Rules;
		while (T--) {
			string Find, Replace;
			getline(cin, Find);
			getline(cin, Replace);
			Rules.push_back({ Find,Replace });
		}
		string word;
		getline(cin, word);
		string newWord;

		for (auto i : Rules) {
			while (word.find(i.first) != string::npos) {
				size_t pos = word.find(i.first);
				int len = i.first.size();
				if (pos == 0)
					newWord = i.second + word.substr(pos + len);
				else
					newWord = word.substr(0, pos) + i.second + word.substr(pos + len);
				word = newWord;
				newWord.clear();
			}
		}
		cout << word << '\n';
	}
}

