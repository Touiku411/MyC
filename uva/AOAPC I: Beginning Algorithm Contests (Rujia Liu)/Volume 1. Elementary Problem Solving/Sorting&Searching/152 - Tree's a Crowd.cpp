#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<iomanip>
#include<climits>
using namespace std;

struct Tree {
    int x, y, z;
    //emplace 加上建構子
 /*   Tree(int in_x, int in_y, int in_z) {
        x = in_x;
        y = in_y;
        z = in_z;
    }*/
};
double ToDistance(const Tree& t1, const Tree& t2) {
    double dist = pow(t1.x - t2.x, 2) + 
                  pow(t1.y - t2.y, 2) + 
                  pow(t1.z - t2.z, 2);
    return sqrt(dist);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<Tree> trees;
    int x, y, z;
    while (true) {
        cin >> x >> y >> z;
        if (x == 0 && y == 0 && z == 0)break;
  /*      trees.emplace_back(x, y, z);*/
        trees.push_back(Tree{ x, y, z });
    }
    vector<int> count(10);
    for (int i = 0; i < trees.size(); ++i) {
        double min_dist = INT_MAX;
        for (int j = 0; j < trees.size(); ++j) {
            if (i == j)continue;
            min_dist = min(min_dist, ToDistance(trees[i], trees[j]));
        }
        if (min_dist < 10) {
            count[static_cast<int>(min_dist)]++;
        }
    }
    for (int c : count) {
        cout << setw(4) << c;
    }
    cout << endl;
}
