#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    while (cin >> N) {
        cin.ignore();
        if (N == 0)break;
        vector<string> lines(N);
        for (int i = 0; i < N; i++) {
            getline(cin, lines[i]);
        }
        vector<int> spaces(N);
        for (int i = 0; i < N; i++) {
            int first = lines[i].find('X');
            int last = lines[i].find_last_of('X');

            spaces[i] = last - first + 1 - count(lines[i].begin() + first,
                                                lines[i].begin() + last + 1,
                                                'X');
        }
        int min_spaces = *min_element(spaces.begin(), spaces.end());
        int total = 0;
        for (int s : spaces) {
            total += s - min_spaces;
        }
        cout << total << endl;
 
    }
}


    
