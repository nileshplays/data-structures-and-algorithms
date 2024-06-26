#include<iostream>
using namespace std;
int countSetBits(int n){
    int count=0;
    while( n > 0 ){
        if(n & 1 ==1){         // and operation of 'n' with 1 ....if result is 1 that is the last bit is 1(set bit)....then we have to right shift
            count++;
        }
        n>>=1;                 //right shift the number
    }
    return count;
}
int main(){
    int a,b; cin>>a>>b;
    int setBit_a=countSetBits(a);
    int setBit_b=countSetBits(b);
    int total= setBit_a + setBit_b;
    cout<<"Total Set bits:  "<<total<<endl;
    return 0;
}