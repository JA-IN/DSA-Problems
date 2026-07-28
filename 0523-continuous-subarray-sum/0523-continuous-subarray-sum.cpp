class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int curr_sum = 0;
        for (int i = 0; i < nums.size(); i++) {

            curr_sum += nums[i];
            int remainder = curr_sum % k;
            if( mp.find(remainder) != mp.end()) {
                if (i - mp[remainder] >= 2) {
                    return true;
                } else {
                    continue;
                }
            
            }
        else{
                mp[remainder] = i;
        }
        }

        return false;
    }
};