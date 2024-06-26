class Solution 
{
    
    
    public:
    
    // function to check if two person knows each other
    bool knows(vector<vector<int>>& M,int a , int b){
        if(M[a][b] == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here
        stack<int> s;
        
        //step1: push all elements in the stack
        for(int i=0 ; i<n ;i++){
            s.push(i);
        }
        
        //step:2 take two of the top elements and pop them
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            if(knows(M ,a,b)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        
        //step:3 single element as potential celeb. in the stack
        int candidate = s.top();
        
        //row check for all zero
        bool rowCheck = false;
        int zeroCount = 0;
        for(int i=0 ; i < n ; i++){
            if(M[candidate][i] == 0){
                zeroCount ++;
            }
        }
        if(zeroCount == n){
            rowCheck = true;
        }
        
        //coulmn check for n-1 times 1
        bool columnCheck = false;
        int oneCount = 0;
        for(int i=0 ; i<n ;i++){
            if(M[i][candidate] == 1){
                oneCount++;
            }
        }
        if(oneCount == n-1){
            columnCheck = true;
        }
        
        if(rowCheck ==true && columnCheck ==true){
            return candidate;
        }
        else{
            return -1;
        }
        
    }
};