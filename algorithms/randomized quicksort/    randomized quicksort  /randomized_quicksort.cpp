#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
void QuickSort(vector<int>& array,int left, int right){
    if(left >= right)return;
    int random_idx = left + rand() % (right - left + 1);
    int pivot = array[random_idx];
    swap(array[random_idx], array[right]);
    int i = left;
    for(int j = left ; j < right ;++j){
        if(array[j] < pivot){
            swap(array[i],array[j]);
            i++;
        }
    }
    swap(array[i], array[right]);
    QuickSort(array, left, i - 1);
    QuickSort(array, i + 1, right);
}

int main() {
    srand(time(NULL));
    vector<int> array = {3,9,1,5,6,8,4};
    QuickSort(array , 0, array.size() - 1);
    for (int num : array) cout << num << " ";
    return 0;
}
