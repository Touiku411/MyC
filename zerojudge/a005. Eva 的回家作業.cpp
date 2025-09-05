#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int x; cin >> x;
	while (x--) {
		vector<int> vec(4);
		bool isdengcha = true;
		for (int i = 0; i < 4; i++) {
			cin >> vec[i];
		}
		int gongcha = vec[1] - vec[0];
		for (int i = 1; i < 4; i++) {		
			if (vec[i] != vec[i - 1] + gongcha) {
				isdengcha = false;
			}
		}
		if(isdengcha){
			vec.push_back(vec[3] + gongcha);
		}
		else {
			vec.push_back(vec[3] * (vec[3] / vec[2]));
		}
		for (int& i : vec) {
			cout << i << " ";
		}
		cout << "\n";
	}
}

