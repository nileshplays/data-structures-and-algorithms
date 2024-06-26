#include<iostream>
using namespace std;

int main(){
    int a,b;
    char op;
    cout<<"Enetr any two numbers: "<<endl;
    cin>>a>>b;
    cout<<"Entter any operator ('+','-','*','/','%'): "<<endl;
    cin>>op;
    switch(op){
        case '+': cout<<"Addition: "<<a+b<<endl;
        break;
        case '-': cout<<"Subtraction: "<<a-b<<endl;
        break;
        case '*': cout<<"Multiplication: "<<a*b<<endl;
        break;
        case '/': cout<<"division: "<<a/b<<endl;
        break;
        case '%': cout<<"Modulo: "<<a%b<<endl;
        break;
        default: cout<<"Default case.";

    }
    
}
