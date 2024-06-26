#include<bits/stdc++.h>
using namespace std;

long long int binarySearch(int n){
    int left=0, right=n;
    long long int mid = left+ (right - left)/2;  
    long long int ans=-1;
    // if we directly add it may go out of integer range so manupulating the formula;

    while(left <= right){
        long long int sq= mid* mid;
        if(sq == n){
            return mid;
        }
        if( n > sq){
            ans = mid;
            left= mid+1;
        }

        else{
            right = mid-1;
        }
        mid = left+ (right - left)/2;
    }
    return ans;
}

double morePrecise(int n, int precision, int tempSol){
    double factor=1;
    double ans = tempSol;

    
    for(int i=0 ; i< precision; i++){
        factor /=10;
        for(double i=ans; i*i < n; i=i+factor){
            ans=i;
        }
    }
    return ans;
}

int main()
{
    // Write your code here.
    cout<<"Enter the no.: "; 
    int n; cin>>n;
    int tempSol = binarySearch(n);
    cout<<"Answer answer is: "<<morePrecise(n, 3, tempSol)<<endl;

    return 0;
}