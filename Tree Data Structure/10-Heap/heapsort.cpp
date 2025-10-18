// Implementing heapsort algorithm using max-heap data structure

#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    public:
    vector<int> heap;

    MaxHeap(){}

    void insert(int val){
        heap.push_back(val);
        int index = heap.size() - 1;
        // Bubble up the new element to maintain heap property
        while(index != 0){
            int parentIndex = (index - 1) / 2;
            if(heap[parentIndex] < heap[index]){
                swap(heap[parentIndex], heap[index]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void maxHeapify(int index, int size){
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if(leftChild < size && heap[leftChild] > heap[largest]){
            largest = leftChild;
        }
        if(rightChild < size && heap[rightChild] > heap[largest]){
            largest = rightChild;
        }
        if(largest != index){
            swap(heap[index], heap[largest]);
            maxHeapify(largest, size);
        }
    }

    void buildMaxHeap(){
        for(int i = heap.size() / 2 - 1; i >= 0; i--){
            maxHeapify(i, heap.size());
        }
    }

    void heapsort(){
        buildMaxHeap();
        for(int i = heap.size() - 1; i > 0; i--){
            swap(heap[0], heap[i]);
            maxHeapify(0, i);
        }
    }
};

int main(){
    MaxHeap maxHeap;
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    for(int val : arr){
        maxHeap.insert(val);
    }

    cout<<"Original array: ";
    for(int val : maxHeap.heap){
        cout<<val<<" ";
    }
    cout<<endl;

    maxHeap.heapsort();

    cout<<"Sorted array using Heapsort: ";
    for(int val : maxHeap.heap){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}