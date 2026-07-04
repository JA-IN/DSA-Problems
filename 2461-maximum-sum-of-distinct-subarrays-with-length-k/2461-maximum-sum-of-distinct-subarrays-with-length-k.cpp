class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        unordered_map<int, int> mp;
        int n = nums.size();
        long long  sum = 0;
        int duplicates = 0 ;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            mp[nums[i]]++;

             if (mp[nums[i]] > 1) {
                duplicates++;
            }
        }
        if(duplicates == 0){
            maxSum = sum ;
        }
        
        for (int i = k; i <n ; i++) {

            sum = sum - nums[i-k];
            sum = sum + nums[i];

            // removing element case 
            mp[nums[i-k]]--;
            if(mp[nums[i-k]] >=1){
                duplicates--;
            }
            // adding element case
            mp[nums[i]]++;
            if(mp[nums[i]] > 1){
                duplicates++;
            }

            if( duplicates == 0){
            if(sum > maxSum) maxSum = sum ;
            }
        }

        return maxSum;
    }
};