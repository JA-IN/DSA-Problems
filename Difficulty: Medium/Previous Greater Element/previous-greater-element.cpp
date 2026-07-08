class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        stack<int>s;
        vector<int>ans;
        for(int i = 0 ; i< n ; i++){
            while(!s.empty() && arr[s.top()] <= arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            else{
                
                ans.push_back(arr[s.top()]);
            }
            s.push(i);
        }
        return ans;
    }
};