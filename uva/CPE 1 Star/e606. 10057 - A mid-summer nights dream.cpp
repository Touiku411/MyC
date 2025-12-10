#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
            cin >> nums[i];
        sort(nums.begin(), nums.end());
        vector<int> mid;
        int right = 0, left = 0;
        if (nums.size() % 2 == 0) {
            left = nums[(nums.size() - 1) / 2];
            right = nums[(nums.size()) / 2];
            for (int i = left; i <= right; ++i) {
                mid.push_back(i);
            }
        }
        else {
            mid.push_back(nums[(nums.size()) / 2]);
        }
        int ans2 = 0;
        for (int m : mid) {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == m)
                    ans2++;
            }
        }
        cout << mid[0] << " " << ans2 << " " << right - left + 1 << endl;
    }
}
