#include<iostream>
using namespace std;
int fibonacci(int n){
    int a=0, b=1, c;
    for(int i=2 ; i<n ; i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main(){
    cout<<"Enter the term: ";
    int n;  cin>>n;
    cout<<"The N'th fibonacci term is: "<<fibonacci(n)<<endl;
    return 0;
}
