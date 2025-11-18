#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

//找到最大
//判斷最大的位置是否在正確位置
//否則將最大移至最上方(flip1)，再翻轉(flip2)
int findPos(vector<int>& vec, int n) {
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] == n)
			return i;
	}
	return -1;
}
int main() {
	
	string input;
	while (getline(cin, input)) {
		vector<int> vec;
		vector<int> res;
		stringstream ss(input);
		string word;
		while (ss >> word) {
			vec.push_back(stoi(word));
		}
		vector<int> ans = vec;
		vector<int> copy = vec;
		sort(copy.begin(), copy.end());
		for (int i = copy.size() - 1; i >= 0; --i) {
			if (vec == copy)break;
			int current = copy[i];
			if (vec[i] == current)continue;
			if (vec[0] == current) {
				//flip2
				reverse(vec.begin(), vec.begin() + i + 1);
				res.push_back(vec.size() - i);
			}
			else {
				int pos = findPos(vec, current);
				//flip1 + flip2
				reverse(vec.begin(), vec.begin() + pos + 1);
				reverse(vec.begin(), vec.begin() + i + 1);
				res.push_back(vec.size() - pos);
				res.push_back(vec.size() - i);
			}
		}
		res.push_back(0);
		for (auto i : ans)
			cout << i << " ";
		cout << endl;
		for (auto i : res)
			cout << i << " ";
		cout << endl;
	}
}

