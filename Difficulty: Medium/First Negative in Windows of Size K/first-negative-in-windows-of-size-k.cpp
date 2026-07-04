class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // code here
        queue<int>q;
        int n = arr.size();
        vector<int>ans;
        for(int i = 0 ; i< k; i++){
            if(arr[i] < 0){
                q.push(i);
            }
        }
        if(q.empty()){
            ans.push_back(0);
        }
        else{
            ans.push_back(arr[q.front()]);
        }
        
        for(int i = k ; i< n; i++){
            
            if(arr[i] < 0){
                q.push(i);
            }
                                        // curr window left limit                            
            while(!q.empty() && q.front() < i-k+1){
                q.pop();
            }
            if(q.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(arr[q.front()]);
            }
        }
        return ans;
    }
};