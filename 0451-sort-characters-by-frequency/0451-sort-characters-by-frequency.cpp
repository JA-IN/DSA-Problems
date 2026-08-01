class Solution {
public:
    string frequencySort(string s) {
        vector<vector<char>>bucket(s.size()+1);

        unordered_map<char,int>mp;
        for(int i = 0 ; i< s.size() ; i++){
            mp[s[i]]++;
        }

        for(auto x :mp){
            bucket[x.second].push_back(x.first);
        }

        string ans = "";

        for(int i = bucket.size()-1 ; i >=1 ; i--){
           for(char ch : bucket[i]){
            ans.append(i , ch);
           }
        }

        return ans;
    }
};