class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        stack<int>s;
        int n = arr.size();
        vector<int>ans;
        for(int i = 0 ; i< n ; i++ ){
            
            while(!s.empty() && arr[s.top()] <= arr[i]){
                s.pop();
                
            }
            if(s.empty()){
                ans.push_back(i+1);
            }
            else{
                int days = i - s.top();
                ans.push_back(days);
            }
            s.push(i);
        }
        return ans;
    }
};