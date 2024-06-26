#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<" Enter the total amount: "<<endl;
    cin>>n;
    int hundred,fifty,twenty,ten,one;
    while(n!=0){
        hundred=n/100;
        n=n%100;
        fifty= n/50;
        n=n%50;
        twenty = n/20;
        n=n%20;
        ten= n/10;
        n=n%10;
        one = n/1;
        n= n%1;
    }
    cout<<"Hundred: "<<hundred<<" ,Fifty: "<<fifty<<" ,Twenty: "<<twenty<<" ,Ten: "<<ten<<" ,One :"<<one<<endl;
}