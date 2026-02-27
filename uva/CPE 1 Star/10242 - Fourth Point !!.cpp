#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
using namespace std;
//找出重複點 第四點為鄰近兩點和-重複點
int main()
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        double res1, res2;
        if (x1 == x3 && y1 == y3) {
            res1 = x2 + x4 - x1;
            res2 = y2 + y4 - y1;
        }
        else if (x1 == x4 && y1 == y4) {
            res1 = x2 + x3 - x1;
            res2 = y2 + y3 - y1;
        }
        else if (x2 == x3 && y2 == y3) {
            res1 = x1 + x4 - x2;
            res2 = y1 + y4 - y2;
        }
        else {
            //x2 == x4 , y2 == y4
            res1 = x1 + x3 - x2;
            res2 = y1 + y3 - y2;
        }
        cout << fixed << setprecision(3) << res1 << " " << res2 << endl;
    }
}

