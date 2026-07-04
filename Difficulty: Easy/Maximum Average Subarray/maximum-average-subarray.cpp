class Solution {
  public:
    int findMaxAverage(vector<int>& arr, int k) {
        // code here
        int n= arr.size();
        int maxSum , sum = 0 ;
        for(int i =0 ; i < k ;i++){
            sum += arr[i];
        }
        maxSum = sum;
        
        int ans = 0 ;
        
        for(int i  = k ; i< n ; i++){
            sum = sum - arr[i-k] + arr[i];
            
            
            if (sum > maxSum) {
                maxSum = sum;
                ans = i - k + 1;
            }
        }
        return ans;
    }
};