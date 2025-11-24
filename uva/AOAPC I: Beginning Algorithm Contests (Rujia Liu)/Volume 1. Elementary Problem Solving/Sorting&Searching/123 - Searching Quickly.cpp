#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

bool find(vector<string> v, string s) {
	for (string word : v) {
		if (word == s)return true;
	}
	return false;
}
string lower(string s) {
	string out;
	for (char c : s) {
		out += tolower(c);
	}
	return out;
}
string upper(string s) {
	string out;
	for (char c : s) {
		out += toupper(c);
	}
	return out;
}
bool cmp(string a, string b) {
	string KeyA, KeyB;
	for (char c : a) {
		if (isupper(c)) {
			KeyA += c;
		}
	}
	for (char c : b) {
		if (isupper(c)) {
			KeyB += c;
		}
	}
	return KeyA < KeyB;
}
int main() {
	int cnt = 1;
	vector<string> res;
	vector<string> ignore;
	string input1;
	while (cin >> input1) {
		if (input1 == "::")break;
		ignore.push_back(input1);
	}
	string input2;
	cin.ignore();
	while (getline(cin, input2)) {
		vector<string> line;
		stringstream ss(input2);
		string word;
		while (ss >> word) {
			line.push_back(word);
		}
		vector<bool> keyword(line.size(), false);
		for (int i = 0; i < line.size(); i++) {
			string str = lower(line[i]);
			if (!find(ignore, str)) {
				keyword[i] = true;
			}
		}
		for (int i = 0; i < line.size(); i++) {
			if (!keyword[i])continue;
			string pi = upper(line[i]);
			string temp;
			for (int k = 0; k < line.size(); k++) {
				if (i == k)temp += pi;
				else temp += (lower(line[k]));
				if (k < line.size() - 1) {
					temp += " ";
				}	
			}
			res.push_back(temp);
		}
	}
	stable_sort(res.begin(), res.end(), cmp);
	for (auto i : res) {
		cout /*<< "第 " <<  cnt++ <<" 個: " */<< i << endl;
	}
}
