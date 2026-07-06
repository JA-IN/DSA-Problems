class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int n = s.size();
        int maxfreq = 0 ;
        
        unordered_map<char,int>window; // to track how what is the freq of the char in the current window
        int left = 0 , right = 0 ;
        int ans = INT_MIN;
        
        
        while(right < n){
            window[s[right]]++;
            int window_length = right - left +1;
            maxfreq = max(maxfreq , window[s[right]]);
            
            if(window_length - maxfreq > k){
                window[s[left]]--;
                left++;
            }
            ans = max(ans , right-left+1);
            right++;
        }
        return ans;
        
    }
};