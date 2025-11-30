#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int dx[] = { 0 ,-1,0,1,-1,-1,1,1 };
int dy[] = { -1 ,0,1,0,-1,1,1,-1 };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt = 1;
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0) {
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }
        vector<vector<int>> ans(n, vector<int>(m , 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '*') {
                    for (int k = 0; k < 8; ++k) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                            if (grid[nx][ny] != '*') {
                                ans[nx][ny]++;
                            }
                        }
                    }
                    
                }
            }
        }
        if(cnt > 1)
            cout << endl;
        cout << "Field #" << cnt++ << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '*')
                    cout << '*';
                else
                    cout << ans[i][j];
            }
            cout << endl;
        }
    }
}
    

