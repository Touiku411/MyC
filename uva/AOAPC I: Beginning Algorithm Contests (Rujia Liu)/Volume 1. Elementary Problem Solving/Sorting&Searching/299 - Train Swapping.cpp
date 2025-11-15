#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int cnt;
void merge(vector<int>& vec, int left, int right, int mid) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = vec[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = vec[mid + 1 + i];
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        }
        else {
            vec[k] = R[j];
            j++;
            cnt += (n1 - i);
        }
        k++;
    }
    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(vector<int>& vec, int left, int right) {
    if (right > left) {
        int mid = left + (right - left) / 2;
        merge_sort(vec, left, mid);
        merge_sort(vec, mid + 1, right);
        merge(vec, left, right, mid);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        cnt = 0;
        int t; cin >> t;
        vector<int> vec(t);
        for (int i = 0; i < t; ++i) {
            cin >> vec[i];
        }
        merge_sort(vec, 0, t - 1);
        cout << "Optimal train swapping takes " << cnt << " swaps.\n";
    }
}
