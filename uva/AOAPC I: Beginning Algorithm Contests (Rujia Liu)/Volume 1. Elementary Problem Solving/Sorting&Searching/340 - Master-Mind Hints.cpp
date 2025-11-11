#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

bool allzero(vector<pair<int,bool>> &vec) {
	for (const auto &p : vec) {
		if (p.first != 0)
			return false;
	}
	return true;
}
int main()
{
	int game = 1;
	int T;
	while (cin >> T && T != 0) {
		cout << "Game " << game++ << ":\n";
		vector<pair<int, bool>>secret;
		for (int i = 0; i < T; ++i) {
			int x; cin >> x;
			secret.push_back({ x,false });
		}
		while (true) {
			int a = 0, b = 0;
			vector<pair<int,bool>>guess;
			for (int i = 0; i < T; ++i) {
				int x; cin >> x;
				guess.push_back({ x,false });
			}
			if (allzero(guess))break;
			for (int i = 0; i < T; ++i) {
				if (secret[i].first == guess[i].first) {
					secret[i].second = true;
					guess[i].second = true;
					a++;
				}
			}
			for (auto &g : guess) {
				for (auto &s : secret) {
					if (g.first == s.first && g.second == false && s.second == false) {
						g.second = true;
						s.second = true;
						b++;
						break;
					}
				}
			}
			cout << "    (" << a << "," << b << ")\n";
			for (auto& s : secret) {
				s.second = false;
			}
		}
	}
} 


