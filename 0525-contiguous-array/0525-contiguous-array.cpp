class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int prefix = 0 ;
        unordered_map<int,int>mp;
        mp[0]= -1;
        int max_length = 0 ;
        for(int i = 0 ; i< nums.size();i++){
            if(nums[i] == 0){
                prefix = prefix -1;
            }
            if(nums[i] ==1){
                prefix = prefix +1;
            }

            if(mp.find(prefix) != mp.end()){
                max_length = max(max_length , i - mp[prefix]);
            }
            if(mp.find(prefix) == mp.end()){
                mp[prefix] = i ;
            }
        }

        return max_length;
    }
};