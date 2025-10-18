// Selection Sort Algorithm
// Author: Ayushi
// Sorts an array in ascending order

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {
        int minIdx = i; // assume current index is minimum
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j; // update minimum index
            }
        }
        swap(arr[i], arr[minIdx]); // place minimum at correct position
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    selectionSort(arr);
    cout << "Sorted array: ";
    for(int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
