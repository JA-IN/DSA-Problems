class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        stack<int>s;
        vector<int>ans(n);
        for(int i = n-1 ; i>=0 ; i--){
            
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = arr[s.top()];
            }
            s.push(i);
        }
        return ans;
    }
};