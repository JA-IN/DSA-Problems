class Solution {
	public:
	int longestUniqueSubstr(string &s) {
		// code here
		vector<int>freq(26, 0);
		int ans = 0 ;
		int left = 0, right = 0, n = s.size();
		while (right < n) {
			if (freq[s[right] - 'a'] == 0) {
				freq[s[right] - 'a'] = 1;
				ans = max(ans, right - left + 1);
				right++;
			}
			else {
				while (freq[s[right] - 'a'] != 0) {
					freq[s[left] - 'a'] = 0 ;
					left++;
				}
				
			}
			
		}
		
		return ans ;
	}
};
