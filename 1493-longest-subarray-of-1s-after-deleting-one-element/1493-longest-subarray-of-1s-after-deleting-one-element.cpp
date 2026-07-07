class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0 , right = 0 ;
        int count_zero = 0 , ans = INT_MIN ;
        
        while(right < n){
            if(nums[right] == 0){
                count_zero++;
            }
            while(count_zero > 1){
                if(nums[left] == 0){
                    count_zero--;
                }
                left++;
            }
            ans = max(ans , right - left +1);
            right++;
        }
        int result = ans -1 ; // -1 because we have exclude the 0 in this window
        return result;
    }
};