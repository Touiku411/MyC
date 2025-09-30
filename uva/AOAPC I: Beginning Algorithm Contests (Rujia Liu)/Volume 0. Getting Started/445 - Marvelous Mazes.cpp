#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
	string input;
	while (getline(cin, input)) {
		int sum = 0;
		int numcmd = 0;
		string out;
		
		for (int i = 0; i < input.size(); i++) {
			if (isdigit(input[i])) {
				sum += input[i] - '0';
			}
			else if (isalpha(input[i])) {
				numcmd = sum;
				sum = 0;
				if (input[i] == 'b') {
					while (numcmd--) {
						out += " ";
					}
				}
				
				else {
					while (numcmd--) {
						out += input[i];
					}
				}
			}
			else {
				numcmd = sum;
				sum = 0;
				if (input[i] == '!') {
					out += "\n";
				}
				else {
					while(numcmd--)
						out += input[i];
				}
			}
		}
		cout << out << endl;
	}

}

