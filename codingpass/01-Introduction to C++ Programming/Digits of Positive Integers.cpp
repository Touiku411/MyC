#include <iostream>
using namespace std;

int main()
{
	string number;
	cin >> number;
	int size = number.length();
	for (int i = 0; i < size; i++)
		cout << number[i] << (i != size-1 ? " " : "\n");
}
