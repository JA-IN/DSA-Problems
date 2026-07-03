class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int maxSum , sum = 0;
        for(int i = 0 ; i < k ;i++){
            sum +=arr[i];
        }
        int n = arr.size();
        maxSum = sum ;
        for(int i = k ; i < n ;i++){
            int remove = arr[i-k];
            int add = arr[i];
            sum = sum - remove + add;
            maxSum = max(maxSum , sum);
        }
        
        return maxSum;
    }
};