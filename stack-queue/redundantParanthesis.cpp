#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    // Write your code here.    
    stack<char> stk;
    for(int i=0 ; i<s.length() ; i++){
        char ch = s[i];
        
        if(ch =='(' || ch=='+' ||ch =='-' || ch== '*' || ch=='/'){
            stk.push(ch);
        }
        else{
            if(ch==')'){
                bool isRedundant = true;
                while(stk.top() != '('){
                    char top = stk.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/' )
                        isRedundant =false;
                    stk.pop();
                }
                
                if(isRedundant){
                    return true;
                }
                stk.pop();
            }
            
        }
    }
    return false;
}
