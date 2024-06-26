#include<bits/stdc++.h>
using namespace std;


void merge(int* arr , int s , int e){
    int mid = (e-s)/2 + s;
    int len1 = mid -s +1;
    int len2 = e - mid ;

    int *first = new int[len1];
    int *second = new int[len1];

    //copy values
    int mainArrIndex = s;
    for(int i =0 ; i<len1 ; i++){
        first[i] = arr[mainArrIndex++];
    }
    mainArrIndex = mid+1;
    for(int i=0 ; i< len2 ; i++){
        second[i] = arr[mainArrIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArrIndex = s;

    while(index1<len1 && index2<len2){
        if(first[index1] < second[index2]){
            arr[mainArrIndex++] = first[index1++];
        }
        else{
            arr[mainArrIndex++] = second[index2++];
        }
    }
    while(index1 < len1){
        arr[mainArrIndex++] = first[index1++];
    }
    while(index2 < len2){
        arr[mainArrIndex++] = second[index2++];
    }

    //delete dynamic memory when work done
    delete []first;
    delete []first;

}

void mergeSort(int* arr , int start , int end){
    if(start >= end){
        return;
    }
    int mid = (end-start)/2 + start;
    //left part sort karna hai
    mergeSort(arr , start, mid);
    //right part sort karna hai
    mergeSort(arr , mid+1 , end);

    //merge
    merge(arr , start, end);

}

int main()
{
    int arr[10] = {4,99,23,4,1,5,1,4,3,56};
    int n = 10;
    mergeSort(arr , 0 ,n-1);
    for(int i =0 ; i< n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}