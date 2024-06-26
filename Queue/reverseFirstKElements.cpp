class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int> s;
        
        for(int i=0 ; i<k ;i++){
            int ele = q.front();
            q.pop();
            s.push(ele);
        }
        
        for(int i=0 ; i<k ;i++){
            int ele = s.top();
            s.pop();
            q.push(ele);
        }
        for(int i=0; i<q.size()-k ; i++){
            int ele = q.front();
            q.pop();
            q.push(ele);
        }
        return q;
    }
};