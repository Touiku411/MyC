#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>

using namespace std;
// P=U*I

double toValue(string s) {
	size_t pos;
	if ((pos = s.find('m')) != string::npos) {
		return stod(s.substr(0, pos)) * 1e-3;
	}
	else if ((pos = s.find('k')) != string::npos) {
		return stod(s.substr(0, pos)) * 1e3;
	}
	else if ((pos = s.find('M')) != string::npos) {
		return stod(s.substr(0, pos)) * 1e6;
	}
	else {
		return stod(s);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	int cnt = 1;
	cin.ignore();
	while (T--) {
		string line;
		getline(cin, line);
		size_t P = line.find("P=");
		size_t U = line.find("U=");
		size_t I = line.find("I=");
		double ans = 0;
		string Concept, Unit;
		if (P != string::npos && U != string::npos && I == string::npos) {
			size_t W = line.find('W',P );
			size_t V = line.find('V',U );
			string p = line.substr(P + 2, W - P - 2);//200m || 200
			string u = line.substr(U + 2, V - U - 2);
			ans = toValue(p) / toValue(u);
			Concept = "I=";
			Unit = "A";
		}
		else if (P != string::npos && U == string::npos && I != string::npos) {
			size_t W = line.find('W', P);
			size_t A = line.find('A', I);
			string p = line.substr(P + 2, W - P - 2);//200m || 200
			string i = line.substr(I + 2, A - I - 2);
			ans = toValue(p) / toValue(i);
			Concept = "U=";
			Unit = "V";
		}
		else if (P == string::npos && U != string::npos && I != string::npos) {
			size_t V = line.find('V', U);
			size_t A = line.find('A', I);
			string u = line.substr(U + 2, V - U - 2);//200m || 200
			string i = line.substr(I + 2, A - I - 2);
			ans = toValue(u) * toValue(i);
			Concept = "P=";
			Unit = "W";
		}
		cout << "Problem #" << cnt++ << '\n';
		cout << Concept << fixed << setprecision(2) << ans << Unit << '\n' << '\n';
	}
}


