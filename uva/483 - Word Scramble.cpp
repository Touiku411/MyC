#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	string input;
	while (getline(cin, input)) {
		vector<string> vec;
		string out;

		for (int i = 0; i < input.size(); i++) {
			if (input[i] == ' ') {
				if (!out.empty()) {
					vec.push_back(out);
					out.clear();
				}	
			}
			else {
				out += input[i];
			}
		
		}
		if (!out.empty()) {
			vec.push_back(out);
			out.clear();
		}
		for (int j = 0; j < vec.size(); j++) {
			reverse(vec[j].begin(), vec[j].end());
		}
		for (int j = 0; j < vec.size(); j++) {
			if (j != vec.size() - 1) {
				cout << vec[j] << " ";
			}
			else
				cout << vec[j];
		}
		cout << endl;
	}
	
	
}

