// Polynomial division
#include <iostream>
using namespace std;

// quotient = dividend / divisor; remainder = dividend % divisor
// provided that dividendDegree >= divisorDegree, and
// neither dividend nor divisor is the zero polynomial
void division(int dividend[], int divisor[], int quotient[], int remainder[],
    int dividendDegree, int divisorDegree, int& quotientDegree, int& remainderDegree);

const int arraySize = 101;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int dividend[arraySize];
        int dividendDegree;
        cin >> dividendDegree;
        for (int i = dividendDegree; i >= 0; i--)
            cin >> dividend[i];

        int divisor[arraySize];
        int divisorDegree;
        cin >> divisorDegree;
        for (int i = divisorDegree; i >= 0; i--)
            cin >> divisor[i];

        int quotient[arraySize] = { 0 };
        int remainder[arraySize] = { 0 };
        int quotientDegree;
        int remainderDegree;
        division(dividend, divisor, quotient, remainder,
            dividendDegree, divisorDegree, quotientDegree, remainderDegree);

        cout << quotientDegree;
        for (int i = quotientDegree; i >= 0; i--)
            cout << " " << quotient[i];
        cout << endl;

        cout << remainderDegree;
        for (int i = remainderDegree; i >= 0; i--)
            cout << " " << remainder[i];
        cout << endl;
    }
}

// quotient = dividend / divisor; remainder = dividend % divisor
// provided that dividendDegree >= divisorDegree, and
// neither dividend nor divisor is the zero polynomial
void division(int dividend[], int divisor[], int quotient[], int remainder[],
    int dividendDegree, int divisorDegree, int& quotientDegree, int& remainderDegree)
{



    for (int i = 0; i <= dividendDegree; i++) {
        remainder[i] = dividend[i];
    }
    quotientDegree = dividendDegree - divisorDegree;
  
        for (int i = dividendDegree; i >= divisorDegree; i--) {
            if (remainder[i] == 0)continue;
            int xishu = remainder[i] / divisor[divisorDegree];
            int pow = i - divisorDegree; //商係數
            quotient[pow] = xishu ; //商次方

            for (int j = 0; j <= divisorDegree; j++) {
                remainder[j + pow] -= xishu * divisor[j]; //新的被除數
            }
           
        }
    remainderDegree = 0;
    for (int i = dividendDegree; i >= 0; i--) {
        if (remainder[i] != 0) {
            remainderDegree = i;
            break;
        }
    }
}
