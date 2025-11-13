#include<iostream>
#include<string>
#include<vector>
#include<sstream> 
#include<climits> 
int Max = INT_MAX;
using namespace std;

void addition(vector<int>& a, vector<int>& b , vector<int>& result) {
	int sumSize = a.size() > b.size() ? a.size() : b.size();
	vector<int> temp(sumSize + 1);
	for (int i = 0; i < a.size(); ++i) {
		temp[i] = a[i];
	}
	for (int i = 0; i < b.size(); ++i) {
		temp[i] += b[i];
	}
	for (int i = 0; i < temp.size() - 1; ++i) {
		if (temp[i] > 9) {
			temp[i + 1] += 1;
			temp[i] -= 10;
		}
	}
	while (temp.size() > 1 && temp.back() == 0) {
		temp.pop_back();
	}
	result = temp;
}
void multiply(vector<int>& a, vector<int>& b, vector<int>& result) {
	int sumSize = a.size() + b.size();
	vector<int> temp(sumSize);
	for (int i = 0; i < b.size(); ++i) {
		for (int j = 0; j < a.size(); ++j) {
			temp[i + j] += b[i] * a[j];
		}
	}
	for (int i = 0; i < temp.size() - 1; ++i) {
		if (temp[i] > 9) {
			temp[i + 1] += temp[i] / 10;
			temp[i] = temp[i] % 10;
		}
	}
	while (temp.size() > 1 && temp.back() == 0) {
		temp.pop_back();
	}
	result = temp;
}
bool cmp(string& s) {//return s > int_max
	string Max_str = to_string(Max);
	if (s.size() > Max_str.size()) {
		return true;
	}
	else if (s.size() < Max_str.size()) {
		return false;
	}
	return s > Max_str;
}

void clean(string& s) {
	size_t first_nonzero = s.find_first_not_of('0');
	if (first_nonzero == string::npos)
		s = "0";
	else
		s = s.substr(first_nonzero);
}
int main()
{
	string input;
	while (getline(cin, input)) {
		stringstream ss(input);
		string n1, op, n2;
		ss >> n1 >> op >> n2;
		clean(n1);
		clean(n2);
		
		vector<int> num1, num2 , result;
		for (int i = n1.length() - 1; i >= 0; --i) {
			num1.push_back(n1[i] - '0');
		}
		for (int i = n2.length() - 1; i >= 0; --i) {
			num2.push_back(n2[i] - '0');
		}
		if (op == "+") 
			addition(num1, num2, result);
		else if (op == "*")
			multiply(num1, num2, result);
		string result_str;
		for (int i = result.size() - 1; i >= 0; --i) {
			result_str += result[i] + '0';
		}

		cout << input << endl;
		if (cmp(n1))
			cout << "first number too big\n";
		if (cmp(n2))
			cout << "second number too big\n";
		if (cmp(result_str))
			cout << "result too big\n";
	}
}



