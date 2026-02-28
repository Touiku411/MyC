#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> vec(40);
vector<int> res;
int fun(vector<int>& vec,int num) {
	for (int i = 0; i < 40; ++i) {
		if (num == vec[i]) {
			num -= vec[i];
			res.push_back(i);
			break;
		}
		else if (num < vec[i]) {
			num -= vec[i - 1];
			res.push_back(i - 1);
			break;
		}
	}
	return num;
}
int main()
{
	vec[0] = 1;
	vec[1] = 2;
	for (int i = 2; i < 40; ++i) {
		vec[i] = vec[i - 1] + vec[i - 2];
	}
	int N;
	cin >> N;
	while (N--) {
		int num;
		cin >> num;
		cout << num << " = ";
		while (num > 0) {
			num = fun(vec, num);
		};
		vector<int> ans(res[0] + 1);
		int idx = 0;
		int t = -1;
		for (int i = res[0] ; i >= 0; i--) {
			
			if (res[idx] == i) {
				cout << "1";
				idx++;
				if (idx >= res.size()) {
					t = i;
					break;
				}
			}
			else {
				cout << "0";
			}
		}
		while (t > 0 && t--) {
			cout << "0";
		}
		cout << " (fib)" << endl;
		res.clear();
	}
}

