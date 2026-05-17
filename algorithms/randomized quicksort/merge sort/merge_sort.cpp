#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int k = left; // for temp
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= right){
        temp[k++] = arr[j++];
    }
    for(int i = left; i<= right; ++i){
        arr[i] = temp[i];
    }
}
void merge_sort(vector<int>& arr, vector<int>& temp, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        merge_sort(arr, temp, left, mid);
        merge_sort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

int main(){
    vector<int> arr = {5, 3 ,2 , 1, 6, 7};
    vector<int> temp(arr.size());

    merge_sort(arr, temp, 0, arr.size() - 1);

    for(int i:arr){
        cout << i << " ";
    }
    cout << '\n';
}
