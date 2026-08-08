class Solution {
	public:
	bool sameFrequency(vector<int>& window, vector<int>& need) {
		for (int i = 0; i < 26; i++) {
			if (window[i] != need[i]) {
				return false;
			}
		}
		return true;
	}
	int search(string &pat, string &txt) {
		// code here
		int n1 = pat.size(), n2 = txt.size();
		
		vector<int>need(26, 0);
		vector<int>window(26, 0);
		
		int ans = 0 ;
		for (int i = 0 ; i < n1 ; i++) {
			need[pat[i] - 'a']++;
		}
		for (int i = 0 ; i < n1 ; i++) {
			window[txt[i] -'a']++;
		}
		
		if (sameFrequency(window, need)) {
			ans++;
		}
		int right = n1;
		for (int i = n1 ; i < n2 ; i++) {
			int remove = txt[i - n1] - 'a';
			int add = txt[i] -'a';
			
			window[remove]--;
			window[add]++;
			
			if (sameFrequency(window, need)) {
				ans++;
			}
		}
		
		return ans;
	}
};
