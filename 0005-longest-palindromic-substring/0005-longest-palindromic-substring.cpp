class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1) {
            return s;
        }

        int left =0 , right =1;
        int max_len = 1;
        for (int i = 0; i < s.size(); i++) {
            int curr_left = i, curr_right = i;
            while(curr_left >= 0 && s[curr_left] == s[i]){
                curr_left--;
            }
             while(curr_right < s.size() && s[curr_right] == s[i]){
                curr_right++;
            }
            while (curr_left >= 0 && curr_right < s.size() &&
                   s[curr_left] == s[curr_right]) {
                curr_left--, curr_right++;
            }

            int curr_length = curr_right - curr_left - 1;
            if (curr_length >= max_len) {
                max_len = curr_length;
                left = curr_left;
                right = curr_right;
            }
        }
        string ans = s.substr(left+1 , right - left - 1);

        return ans;
    }
};