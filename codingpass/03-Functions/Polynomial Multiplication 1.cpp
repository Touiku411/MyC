// Polynomial multiplication
#include <iostream>
using namespace std;

const int arraySize = 101;

// product = multiplicand * multiplier provided that
// neither multiplicand nor multiplier is the zero polynomial
void multiplication(int multiplicand[], int multiplier[], int product[],
    int multiplicandDegree, int multiplierDegree, int& productDegree);

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int multiplicand[arraySize];
        int multiplicandDegree;
        cin >> multiplicandDegree;
        for (int i = multiplicandDegree; i >= 0; i--)
            cin >> multiplicand[i];

        int multiplier[arraySize];
        int multiplierDegree;
        cin >> multiplierDegree;
        for (int i = multiplierDegree; i >= 0; i--)
            cin >> multiplier[i];

        int product[2 * arraySize] = { 0 };
        int productDegree;
        multiplication(multiplicand, multiplier, product,
            multiplicandDegree, multiplierDegree, productDegree);

        cout << productDegree;
        for (int i = productDegree; i >= 0; i--)
            cout << " " << product[i];
        cout << endl;
    }
}

// product = multiplicand * multiplier provided that
// neither multiplicand nor multiplier is the zero polynomial
void multiplication(int multiplicand[], int multiplier[], int product[],
    int multiplicandDegree, int multiplierDegree, int& productDegree)
{
    productDegree = multiplicandDegree + multiplierDegree;
    for (int i = multiplicandDegree; i >= 0 ; i--) {
        for (int j = multiplierDegree; j >= 0; j--) {
            product[i + j] += multiplicand[i] * multiplier[j];
        }
    }

}
