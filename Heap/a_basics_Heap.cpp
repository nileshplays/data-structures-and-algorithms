#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
        int arr[100];
        int size =0;
        Heap(){
            arr[0] = -1;
            size = 0;
        }
    void insert(int value){
        size = size +1;
        int index = size;
        arr[index] = value;
        while(index>1){
            int parent = index/2;
            if(arr[parent] < arr[index] ){
                swap(arr[parent] , arr[index]);
                index = parent;
            }
            else{
                return; 
            }
        }
    }
    
    void deleteFromHeap(){
        if(size == 0){
            cout<<"Nothing to Delete. "<<endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        //Take Root Node to its correct position
        int i=1;
        while(i < size){
            int leftIndex = 2*i;
            int rightIndex = 2*i +1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i],  arr[leftIndex]);
                i= leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i],  arr[rightIndex]);
                i= rightIndex;
            }
            else{
                return;
            }
        }

    }

    void heapify(int arr[], int n , int i){
        int largest = i;
        int left = 2*i;
        int right = 2*i +1;

        if(left <= n && arr[largest] < arr[left]){
            largest = left;
        }
        if(right <= n && arr[largest] < arr[right]){
            largest = right;
        }
        
        if(largest != i){
            swap(arr[largest] , arr[i]);
            heapify(arr , n ,largest);
        }
    }

    void heapSort(int arr[] , int n ){
        int size = n;
        while(size > 1){
            swap(arr[size] , arr[1]);
            size--;
            
            heapify(arr , size ,1);
        }
    }

    void print(){
        for(int i=1; i<= size ;i++){
            cout<<arr[i] <<" ";
        }
        cout<<endl;
    }
};

int main(){
    // int value; cin>>value;
    Heap h;
    /*
    h.insert(12);
    h.insert(50);
    h.print();
    h.insert(20);
    h.insert(1);
    h.print();
    h.insert(45);
    h.insert(23);
    h.print();
    h.insert(21);
    h.insert(5);
    h.insert(99);
    h.print();
    cout<<"Now delete function call:"<<endl;
    h.deleteFromHeap();
    h.print();
    h.deleteFromHeap();
    h.print();
    h.deleteFromHeap();
    h.print();
    */
/*
   int arr[6] = {-1, 54,53, 55,52,50};
   int n = 5;
    for(int i = n/2 ; i>0 ; i--){
        h.heapify(arr,  n , i);
    }
    cout<<"Printing array :"<<endl;
    for(int i =1 ; i<= n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    h.heapSort(arr, n );
    cout<<"Printing Sorted array :"<<endl;
    for(int i =1 ; i<= n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
*/

    priority_queue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(7);
    pq.push(8);
    pq.push(2);
    pq.push(5);
    cout<<"MaxHeap top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"MaxHeap top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"MaxHeap top: "<<pq.top()<<endl;

    priority_queue<int, vector<int> , greater<int> > minHeap;

    minHeap.push(7);
    minHeap.push(3);
    minHeap.push(6);
    cout<<"MinHeap top: "<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"MinHeap top: "<<minHeap.top()<<endl;
    return 0;
}