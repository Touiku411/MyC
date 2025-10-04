#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;



int main()
{
	string input;
	while (getline(cin, input)) {
		stringstream ss(input);
		string word;
		vector<int> coef;
		vector<int> Check(input.size());
		while (ss >> word) {
			coef.push_back(stoi(word));
		}
		bool allzero = true;
		for (int i = 0; i < coef.size(); i++) {
			if (coef[i] < 0) {
				Check[i] = 1;
			}
			if (coef[i] != 0)
				allzero = false;
		}

		if (allzero) {
			cout << "0" << endl;
			continue;
		}

		for (int i = 0; i < coef.size(); i++) {
			coef[i] = abs(coef[i]);
		}

		int degree = coef.size() - 1;
		int start = 0;
		for (int i = 0; i < coef.size(); i++) {
			if (coef[i] == 0) {
				degree--;
				start++;
				continue;
			}
			break;
		}
		int end = coef.size() - 1;
		for (int i = end; i >= 0; i--) {
			if (coef[i] == 0) {
				end--;
				continue;
			}
			break;
		}
		string term;
		for (int i = start; i <= end; i++) {
			long long c = coef[i];
			if (c == 0) {
				degree--;
				continue;
			}
			
			if (c == 1) {
				if (Check[i] != 1) {
					if ( start == end && degree == 0) {
						term += "1";
					}
					else if (degree == 0) {
						term += "+ 1";
					}
					else if (i == start) {
						term += "x";
					}
					
					else {
						term += "+ x";
					}
				}
				else {
					if (start == end && degree == 0) {
						term += "-1";
					}
					else if (degree == 0) {
						term += "- 1";
					}
					else if (i == start) {
						term += "-x";
					}
					
					else {
						term += "- x";
					}
				}
			}
			else {
				//+
				if (Check[i] != 1) {
					
					if (start == end && degree == 0) {
						term += to_string(c);
					}
					 else if (degree == 0) {
						term += "+ " + to_string(c);
					}
					 else if (i == start) {
						 term += to_string(c) + "x";
					}
					else {
						term += "+ " + to_string(c) + "x";

					}
				}
				//-
				else {
					if (start == end && degree == 0) {
						term += "-" + to_string(c);
					}
					else if (degree == 0) {
						term += "- " + to_string(c);
					}
					else if (i == start) {
						term += "-" + to_string(c) + "x";
					}
					
					else {
						term += "- " + to_string(c) + "x";
					}
				}
			}

			if (degree != 0) {
				if (i != end) {
					if (degree == 1) {
						term += " ";
					}
					else {
						term += "^" + to_string(degree) + " ";
					}
				}
				else {
					if(degree != 1)
						term += "^" + to_string(degree);	
				}
			}
			degree--;
		}
		cout << term << endl;
	}
	
}

