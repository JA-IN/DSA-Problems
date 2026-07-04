class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0 ,right = 0, n = nums.size();
        long long sum = 0, ans = INT_MAX;
        while (right < n) {

            sum += nums[right];
            while (sum >= target) {
                
                if(ans > right-left +1) ans = right - left +1;
                
                sum -= nums[left];
                left++;
            }
            right++;
        }
        if(left == 0) return 0 ;
        
        return ans;
    }
};