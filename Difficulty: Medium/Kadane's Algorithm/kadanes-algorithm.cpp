class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int ans = arr[0];
        int best_max_ans = arr[0];
        
        for(int i = 1 ; i< arr.size() ; i++)
        {
            best_max_ans = max(best_max_ans + arr[i] , arr[i]);
            
            ans = max(ans , best_max_ans);
        }
        
        return ans;
    }
};