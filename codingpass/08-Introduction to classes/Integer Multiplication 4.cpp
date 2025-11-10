#include <iostream>
#include <cstring>
using namespace::std;

class HugeInt
{
public:
    int size;
    int* digit;

    // product = multiplicand * multiplier
    void multiplication(HugeInt multiplier, HugeInt& product);
};

int main()
{
    char strA[251], strB[251];

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> strA >> strB;

        HugeInt multiplicand;
        multiplicand.size = strlen(strA);
        multiplicand.digit = new int[multiplicand.size];
        for (int i = 0; i < multiplicand.size; ++i)
            multiplicand.digit[i] = strA[multiplicand.size - 1 - i] - '0';

        HugeInt multiplier;
        multiplier.size = strlen(strB);
        multiplier.digit = new int[multiplier.size];
        for (int i = 0; i < multiplier.size; ++i)
            multiplier.digit[i] = strB[multiplier.size - 1 - i] - '0';

        HugeInt product;
        multiplicand.multiplication(multiplier, product);

        for (int i = product.size - 1; i >= 0; i--)
            cout << product.digit[i];
        cout << endl;

        delete[] multiplicand.digit;
        delete[] multiplier.digit;
        delete[] product.digit;
    }
}

// product = multiplicand * multiplier
void HugeInt::multiplication(HugeInt multiplier, HugeInt& product)
{
    if ((size == 1 && digit[0] == 0) ||
        (multiplier.size == 1 && multiplier.digit[0] == 0))
    {
        product.size = 1;
        product.digit = new int[1]();
        product.digit[0] = 0;
        return;
    }
    product.size = multiplier.size + this->size;
    product.digit = new int[product.size]();
    for (int i = 0; i < multiplier.size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            product.digit[i + j] += multiplier.digit[i] * this->digit[j];
        }
    }
    for (int i = 0; i < product.size - 1; ++i) {
        if (product.digit[i] > 9) {
            product.digit[i + 1] += product.digit[i] / 10;
            product.digit[i] = product.digit[i] % 10;
        }
    }
    while (product.size > 0 && product.digit[product.size - 1] == 0) {
        product.size--;
    }
}
