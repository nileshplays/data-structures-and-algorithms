vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
        vector<long long> ans;
        deque<long long int> dq;
        
        //process first window of K size
        for(int i=0 ; i<K ; i++){
            if(A[i] < 0){
                dq.push_back(i);
            }
        } 
            //store answer of the first K size window
        if(dq.size() > 0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
            
        
        //Process for remaining  window
        
        for(int i= K; i<N ;i++){
            //removing the element from the dequeue
            if(!dq.empty() && i - dq.front() >=K){
                dq.pop_front();
            }
            //adding in the dequeu of th new element for the new window
            if(A[i] < 0){
                dq.push_back(i);
            }
            
            if(dq.size() > 0){
                ans.push_back(A[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
        
 }