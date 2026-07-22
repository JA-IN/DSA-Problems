class Solution {
  public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        // code here
        sort(greed.begin() , greed.end());
        sort(cookie.begin() , cookie.end());

        int ans = 0 ;
        int curr_child = 0 ;
        for(int i = 0 ; i< cookie.size();i++){
            if(cookie[i] >= greed[curr_child]){
                ans++;
                curr_child++;
                if(curr_child == greed.size()) break;
            }
        }

        return ans;
    }
};