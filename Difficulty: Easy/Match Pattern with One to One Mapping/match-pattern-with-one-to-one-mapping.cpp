class Solution {
	public:
	vector<string> matchingStrings(vector<string>& d, string& pat) {
		// code here
		vector<string>ans;
		int n = d.size();
		for (int i = 0 ; i<n; i++) {
			unordered_map<char, char>mp1;
			unordered_map<char, char>mp2;
			int count = 0 ;
			string word = d[i];
			if(word.size() != pat.size()){
			    continue;
			}
			for (int j = 0 ; j < pat.size() ; j++) {
				if ((mp1.find(pat[j]) != mp1.end()) && mp1[pat[j]] != word[j]) {
					break;
				}
				if ((mp2.find(word[j]) != mp2.end()) && mp2[word[j]] != pat[j]) {
					break;
				}
				mp1[pat[j]] = word[j];
				mp2[word[j]] = pat[j];
				count++;
			}
			if (count == pat.size()) {
				ans.push_back(word);
			}
		}
		
		return ans;
	}
};
