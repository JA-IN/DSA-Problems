class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int ans = 0 ;
        int left = 0 , right = 0  ;
        int n = s.size();
        while(right < n){
            if(mp[s[right]] == 0){
                mp[s[right]] =1;
                ans = max(ans , right -left +1);
                right++;
            }
            else{
                while(mp[s[right]] == 1){
                    mp[s[left]] = 0 ;
                    left++;
                }
            }
            
        }
        return ans;
    }
};