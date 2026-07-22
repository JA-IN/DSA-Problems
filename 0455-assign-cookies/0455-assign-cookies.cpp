class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());

        int ans = 0 ;
        int curr_child = 0 ;
        for(int i = 0 ; i< s.size();i++){
            if(s[i] >= g[curr_child]){
                ans++;
                curr_child++;
                if(curr_child == g.size()) break;
            }
        }

        return ans;
    }
};