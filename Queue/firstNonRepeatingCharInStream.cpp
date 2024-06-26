class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char, int> count;
		    queue<char> q;
		    string ans ="";
		    
		    for(int i=0 ; i<A.length() ; i++){
		        char ch = A[i];
		        //Count increment
		        count[ch]++;
		        
		        //Push the element in the queue
		        q.push(ch);
		        
		        //Check if the character is repeating 
		        while(!q.empty()){
		            //for repeating
		            if( count[q.front()] > 1){
		                q.pop();
		            }
		            else{
		                //non-repeating
		                ans.push_back(q.front());
		                break;
		            }
		            
		        }
		        if(q.empty()){
		            ans.push_back('#');
		        }
		        
		    }
		    return ans;
		}

};