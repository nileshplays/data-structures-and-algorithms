#include<iostream>
using namespace std;
int lineaSearch(int arr[], int n , int key){
    for( int i=0; i<n ; i++){
        if(arr[i]==key){
            cout<<i<<endl;
            return i;
        }
    }
    return -1;
}
int main(){
    int n,key,arr[20];
    cout<<"Enter the no. of elements: ";
    cin>>n;
    cout<<"Enter the key: ";
    cin>>key;
    cout<<"Enter the  elements: "<<endl;
    for(int i=0;i<n ; i++){
        cin>>arr[i];
    }
    cout<<"Element at "<<lineaSearch(arr,n,key)<<"th index."<<endl;
    
    return 0;
}