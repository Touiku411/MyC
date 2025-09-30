#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;


int main()
{
	string input;
	while (getline(cin, input)) {
		
		stringstream ss(input);
		string word;
		bool first = true;

		while (ss >> word) {
			if (!first) {
				cout << " ";
			}
			reverse(word.begin(), word.end());
			cout << word ;
			first = false;
		}
		cout << endl;
	}
	
	
}

