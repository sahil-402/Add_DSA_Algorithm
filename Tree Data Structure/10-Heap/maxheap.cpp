// Making a max-heap in C++

/* Heap is a specialized tree-based data structure that satisfies the heap property.
   In a max-heap, for any given node C, if P is a parent node of C, then the key (the value) of P is greater than or equal to the key of C.
   This property must be true for all nodes in the heap.
*/

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

    int getMax(){
        if(heap.empty()){
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }

    void removeMax(){
        if(heap.empty()){
            throw runtime_error("Heap is empty");
        }
        heap[0] = heap.back();
        heap.pop_back();
        maxHeapify(0);
    }

    void maxHeapify(int index){
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if(leftChild < heap.size() && heap[leftChild] > heap[largest]){
            largest = leftChild;
        }
        if(rightChild < heap.size() && heap[rightChild] > heap[largest]){
            largest = rightChild;
        }
        if(largest != index){
            swap(heap[index], heap[largest]);
            maxHeapify(largest);
        }
    }
};

int main(){
    MaxHeap maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(30);

    cout<<"Max element: "<<maxHeap.getMax()<<endl; // Should print 30

    maxHeap.removeMax();
    cout<<"Max element after removing max: "<<maxHeap.getMax()<<endl; // Should print 20

    return 0;
}