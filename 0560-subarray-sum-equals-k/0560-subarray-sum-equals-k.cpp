class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        int ans = 0 ;
        int curr_sum = 0 ;
        for(int i = 0 ; i< nums.size() ; i++){
             curr_sum += nums[i];
            int req = curr_sum - k ;
            if(mp.find(req) != mp.end()){
                ans += mp[req];
            }
            mp[curr_sum]++;
            
        }

        return ans;
    }
};