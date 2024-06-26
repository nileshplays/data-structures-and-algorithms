#include <bits/stdc++.h>
using namespace std;

int firstOcc(int arr[] , int n, int key){
    int start=0 ,end = n-1;
    int mid = start + (end - start)/2;
    int ans =-1;
    while(start <= end){
        if( arr[mid] == key){
            ans = mid;
            end = mid-1;
        }
        else if( mid < key){
            start = mid + 1;
        }
        else if( mid > key){
            end = mid -1;
        }
        mid = start + ( end -start)/2;
    }
    return ans;
}
int lastOcc(int arr[] , int n, int key){
    int start=0 ,end = n-1;
    int mid = start + (end - start)/2;
    int ans =-1;
    while(start <= end){
        if( arr[mid] == key){
            ans = mid;
            start = mid+1;
        }
        else if( mid < key){
            start = mid + 1;
        }
        else if( mid > key){
            end = mid -1;
        }
        mid = start + ( end -start)/2;
    }
    return ans;
}



int main(){

    int arr[5] = {1,2,3,4,5};
    
    cout<< "First Occurance of Key is at Index: "<< firstOcc(arr , 5 , 3)<< endl;
    
    cout<< "Last Occurance of Key is at Index: "<< lastOcc(arr , 5 , 3)<< endl;

    
}
