// Making a min-heap in C++

/* Heap is a specialized tree-based data structure that satisfies the heap property.
   In a min-heap, for any given node C, if P is a parent node of C, then the key (the value) of P is less than or equal to the key of C.
   This property must be true for all nodes in the heap.
*/

#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    public:
    vector<int> heap;

    MinHeap(){}

    void insert(int val){
        heap.push_back(val);
        int index = heap.size() - 1;
        // Bubble up the new element to maintain heap property
        while(index != 0){
            int parentIndex = (index - 1) / 2;
            if(heap[parentIndex] > heap[index]){
                swap(heap[parentIndex], heap[index]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    int getMin(){
        if(heap.empty()){
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }

    void removeMin(){
        if(heap.empty()){
            throw runtime_error("Heap is empty");
        }
        heap[0] = heap.back();
        heap.pop_back();
        minHeapify(0);
    }

    void minHeapify(int index){
        int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if(leftChild < heap.size() && heap[leftChild] < heap[smallest]){
            smallest = leftChild;
        }
        if(rightChild < heap.size() && heap[rightChild] < heap[smallest]){
            smallest = rightChild;
        }
        if(smallest != index){
            swap(heap[index], heap[smallest]);
            minHeapify(smallest);
        }
    }
};

int main(){
    MinHeap minHeap;
    minHeap.insert(10);
    minHeap.insert(5);
    minHeap.insert(20);
    minHeap.insert(3);

    cout<<"Minimum element: "<<minHeap.getMin()<<endl; // Should print 3

    minHeap.removeMin();
    cout<<"Minimum element after removing min: "<<minHeap.getMin()<<endl; // Should print 5

    return 0;
}