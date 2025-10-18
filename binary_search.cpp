// Binary Search Algorithm
// Author: Ayushi
// Searches for 'target' in a sorted 'arr' and returns the index, -1 if not found

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;  // found
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;  // not found
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50}; // must be sorted
    int target = 40;
    int index = binarySearch(arr, target);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
