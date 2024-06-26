#include<bits/stdc++.h>
using namespace std;

int partition(int *arr, int s , int e){

    int pivot = arr[s];
    int count = 0;

    for(int i=s+1 ; i<=e ;i++){
        if( arr[i] <= pivot){
            count++;
        }
    }

    //place pivot to the right position
    int pivotIndex = s + count;
    swap(arr[pivotIndex] , arr[s]);

    //left and right part

    int i = s ;
    int j = e;
    while(i < pivotIndex && j> pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        
        if(i < pivotIndex && j> pivotIndex){
            swap(arr[i++] , arr[j--]);
        }

    }
    return pivotIndex;

}

void quickSort(int *arr, int s , int e){
    if(s >= e){  
        return;
    }

    int p = partition(arr , s,e);

    //recursively solve left of partition
    quickSort(arr, s , p-1);
    //recursively solve right of partition
    quickSort(arr, p+1 , e);
}

int main(){
    int arr[10] = {3,7,1,90,3,5,5,3,2,8};
    int n = 10;
    quickSort(arr , 0 , n-1);
    for(int i=0; i< n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}