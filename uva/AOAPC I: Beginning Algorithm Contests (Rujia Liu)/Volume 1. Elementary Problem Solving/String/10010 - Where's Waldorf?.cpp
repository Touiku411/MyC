#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

int main()
{

	int T; cin >> T;
	while (T--) {
		int m, n; cin >> m >> n;
		vector<string> grid(m);	
		for (int i = 0; i < m; i++) {
			cin >> grid[i];
			for (int j = 0; j < n; j++) {
				grid[i][j] = tolower(grid[i][j]);
			}
		}
		int k; cin >> k;
		vector<string> word(k);
		for (int i = 0; i < k; i++) {
			cin >> word[i];
			for (int j = 0; j < word[i].length(); j++) {
				word[i][j] = tolower(word[i][j]);
			}
		}
		
		for (int t = 0; t < k; t++) {
			string WordToFind = word[t];
			bool found = false;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (grid[i][j] == WordToFind[0]) {
						for (int d = 0; d < 8; d++) {
							bool match = true;
							for (int l = 0; l < WordToFind.length(); l++) {
								int ni = i + l * dx[d];
								int nj = j + l * dy[d];
								if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
									match = false;
									break;
								}
								if (grid[ni][nj] != WordToFind[l]) {
									match = false;
									break;
								}
							}
							if (match) {
								cout << i + 1 << " " << j + 1 << endl;
								found = true;
								break;
							}
						}
					}
					if (found)break;
				}
				if (found)break;
			}
		}
		if (T > 0) {
			cout << endl;
		}
 	}
} 


