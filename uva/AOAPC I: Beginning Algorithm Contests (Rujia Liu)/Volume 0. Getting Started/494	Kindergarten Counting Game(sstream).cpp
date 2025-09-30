#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main()
{
	string input;
	while (getline(cin,input)) {
	
		for (int i = 0; i < input.size(); i++) {
			char c = input[i];
			if (!isalpha(c) && c != ' ') {
				input[i] = ' ';
			}
		}
		stringstream ss(input);
		string word;
		int cnt = 0;

		while (ss >> word) {
			cnt++;
		/*	cout << word << " ";*/
		}
		//cout << endl;
		cout << cnt << endl;
	}
	
}

