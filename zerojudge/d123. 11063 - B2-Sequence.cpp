#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool isB2(vector<int> vec) {
	
		if (vec.empty() || vec[0] < 1)
			return false;
		for (int i = 0; i < vec.size() - 1; i++) {
			if (vec[i] >= vec[i + 1])
				return false;
		}
		set<int> s;
		for (int i = 0; i < vec.size(); i++) {
			for (int j = i; j < vec.size(); j++) {
				int sum = vec[i] + vec[j];
				if (s.count(sum))
					return false;
				s.insert(sum);
					
			}
		}
	
	return true;
}
int main()
{
	int n; 
	int cnt = 1;
	while (cin >> n) {
		vector<int> vec;
		while (n--) {
			int x; 
			cin >> x;
			vec.push_back(x);
		}
		cout << "Case #" << cnt++;
		if (isB2(vec)) {
			cout <<  ": It is a B2-Sequence.\n";
		}
		else {
			cout << ": It is not a B2-Sequence.\n";
		}
	}
}

