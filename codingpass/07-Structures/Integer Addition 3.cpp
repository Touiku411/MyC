#include <iostream>
#include <cstring>
using namespace::std;
struct HugeInt
{
	int size;
	int* digit;
};
// sum = addend + adder
void addition(HugeInt addend, HugeInt adder, HugeInt& sum);
int main()
{
	char strA[251], strB[251];
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		cin >> strA >> strB;
		HugeInt addend;
		addend.size = strlen(strA);
		addend.digit = new int[addend.size];
		for (int i = 0; i < addend.size; ++i)
			addend.digit[i] = strA[addend.size - 1 - i] - '0';
		HugeInt adder;
		adder.size = strlen(strB);
		adder.digit = new int[adder.size];
		for (int i = 0; i < adder.size; ++i)
			adder.digit[i] = strB[adder.size - 1 - i] - '0';
		HugeInt sum;
		addition(addend, adder, sum);
		for (int i = sum.size - 1; i >= 0; i--)
			cout << sum.digit[i];
		cout << endl;
		delete[] addend.digit;
		delete[] adder.digit;
		delete[] sum.digit;
	}
}
// sum = addend + adder
void addition(HugeInt addend, HugeInt adder, HugeInt& sum)
{
	int MaxSize = (addend.size > adder.size) ? addend.size : adder.size;
	sum.size = MaxSize + 1;
	sum.digit = new int[sum.size]();
	if (addend.digit[0] == 0 && adder.digit[0] == 0 && MaxSize == 1)
	{
		sum.size = 1;
		sum.digit[0] = 0;
		return;
	}
	for (int i = 0; i < MaxSize; i++) {
		if (i < addend.size) {
			sum.digit[i] += addend.digit[i];
		}
		if (i < adder.size) {
			sum.digit[i] += adder.digit[i];
		}
	}
	for (int i = 0; i < MaxSize; i++) {
		if (sum.digit[i] > 9) {
			sum.digit[i] -= 10;
			sum.digit[i + 1] += 1;
		}
	}
	while (sum.size > 1 && sum.digit[sum.size - 1] == 0) {
		sum.size--;
	}
}
