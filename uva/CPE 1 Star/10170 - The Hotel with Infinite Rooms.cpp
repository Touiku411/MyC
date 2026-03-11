#include <iostream>
using namespace std;

int main()
{
    long long s, d;
    while (cin >> s >> d) {
        long long cur_day = 0;
       
        while (true) {
            cur_day += s;
            if (cur_day >= d) {
                cout << s << endl;
                break;
            }
            s++;
        }
    }
    
}
#include <iostream>
//更簡單解法  
// 1 2 2 3 3 3 4 4 4 4
//           -
// 若s d (1, 6) 要輸出 3
// s d  只要當 s < d 時候，d-=s, s++ ， 當 s >= d 時s就是答案
// 1 6
// 2 5
// 3 3

using namespace std;


int main() {
	long long s, d;
	while (cin >> s >> d) {
		while (s < d) {
			d -= s;
			s++;
		}
		cout << s << endl;
	}
}
