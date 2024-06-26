#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  // Write your code here

  // odd condition;;;
  if(str.length() %2 != 0){
    return -1;
  }

  stack<char> s;
  for( int i=0; i<str.length() ; i++){
    char ch = str[i];
    if(ch == '{'){
      s.push(ch);
    }
    else {
      if( !s.empty() && s.top()=='{'){
          s.pop();
      }
      else{
          s.push(ch);
      }
    }

  }
  int open =0;
  int closed = 0;
  while( !s.empty()){
    if( s.top() == '{'){
      open += 1;
    }
    else{
      closed += 1;
    }
    s.pop();
  }

  int count = (open +1)/2 + (closed +1)/2;
  return count;

}