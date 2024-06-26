#include<iostream>
#include<limits.h>
using namespace std;
int getMin(int num[],int n){
    int min = INT_MAX;
    for(int i=0 ; i<n ;i++){
        if(num[i]<min)
            min = num[i];
    }
    return min;
}
int getMax(int num[],int n){
    int max = INT_MIN;
    for(int i=0 ; i<n ;i++){
        if(num[i]>max)
            max = num[i];
    }
    return  max;
}
int main(){
    int arr[20],n;
    cout<<"Enter the size: ";  cin>>n;
    cout<<"Enter the elements: "<<endl;
    for(int i=0 ; i< n ;i++){
        cin >> arr[i];
    }
    cout<<"MAX no. is :  "<<getMax(arr,n)<<endl;
    cout<<"MIN no. is :  "<<getMin(arr,n)<<endl;
    return 0;
}