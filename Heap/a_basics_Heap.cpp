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
    return 0;
}