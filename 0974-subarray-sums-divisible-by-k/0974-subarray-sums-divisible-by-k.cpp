class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int ans = 0 , curr_sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            curr_sum += nums[i];
            int remainder = ((curr_sum % k)+k)%k;
           if(mp.find(remainder) != mp.end()){
            ans +=mp[remainder];
           }
          
            mp[remainder]++;
        
        } 
        return ans;
    }
};