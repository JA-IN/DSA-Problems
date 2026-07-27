class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        long long total_sum  , sum = 0 ;
        for(int i = 0 ; i<n ;i++){
            sum += arr[i];
        }
        n = n+1;
        total_sum = (long long) n * (n+1) / 2;
        
        long long ans = total_sum - sum ;
        
        return ans;
    }
};