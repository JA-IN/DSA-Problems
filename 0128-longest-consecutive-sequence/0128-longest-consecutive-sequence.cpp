class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int n = nums.size();
        if(n==0) return 0 ;

        int ans = 1 ;
        for(int i = 0 ; i< n ; i++){
        s.insert(nums[i]);
        }

        for(auto i : s)
        {
            if(s.count(i-1) ){
                continue;
            }
            else{
            int count = 0 ;
            int val = i;
            while(s.count(val)){
                count++;
                val++;
            }
            ans = max(ans , count);
            }
        }

        return ans;
    }
};