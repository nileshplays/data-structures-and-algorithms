class SpecialStack {
    stack<int> s;
    int mini ;

    public:
        
    void push(int data) {
        // for 1st element just push in the stack
        if(s.empty()){
            s.push(data);
        }
        // for rest elements
        
        if(data < mini){
            int val = 2*data - mini;
            s.push(val);
            mini = val;
        }
        else{
            s.push(data);
        }
        
    }

    void pop() {

        int current = s.top();
        //underflow condition check
        if(s.empty() ){
            return;
        }
        
        if(current < mini){
            pop();
        }
        // else{
        //     int val = 2*mini - current;
        //     mini = val;
        //     pop();
        // }
        return;
    }

    int top() {
        // Implement the top() function.
        int current = s.top();
        if(s.empty()){
            return -1;
        }
        
        if(current < mini){
            return current;
        }
        else{
            return mini; 
        }
        
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty()){
            return -1;
        }
        return mini;
    }  
};