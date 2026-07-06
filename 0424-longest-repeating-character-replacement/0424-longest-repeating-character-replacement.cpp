class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>window;
        int maxFreq = 0 ;
        int n = s.size();
        
        
        
        int left = 0 , right = 0 ;
        int ans = INT_MIN;
        while(right < n){
            int window_length = right - left +1;
            window[s[right]]++;

             maxFreq = max(maxFreq , window[s[right]]);


            if(window_length - maxFreq > k){

                window[s[left]]--;
                left++;

            }
            ans = max(ans , right-left+1);
            right++;
        }
        return ans;
    }
};