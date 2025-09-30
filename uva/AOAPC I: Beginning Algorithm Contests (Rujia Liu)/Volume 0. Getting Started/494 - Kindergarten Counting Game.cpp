#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
	string input;
	while (getline(cin,input)) {
		string word;
		vector<string> vec;
		for (int i = 0; i < input.size(); i++) {
			if (isalpha(input[i])) {
				word += input[i];
			}
			else {
				if (!word.empty()) {
					vec.push_back(word);
					word.clear();
				}
			}
		}
		if (!word.empty()) {
			vec.push_back(word);
		}
		cout << vec.size() << endl;
	}
	
}

