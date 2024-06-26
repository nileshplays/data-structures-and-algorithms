#include <bits/stdc++.h> 
int selectionSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for(int i=0; i<n ; i++){
        int min = i;
        for(int j=i+1 ; j<n; j++){
            if(arr[j] < arr[min]){
                min=j;
            }
        }
        swap(arr[min], arr[i]);
    }
    return arr;
}
int main(){
    int n;
    cout<<"Enter no. of elements: "; cin>>n;
    int arr[n];
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    selectionSort(arr, n);
    return 0;
}
