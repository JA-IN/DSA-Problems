class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        int n = s.size();
        if(k == n){
            return "0";
        }
        string ans = "";
        for(int i = 0 ; i < n ; i++){
            while(!s.empty() && k > 0 && ans.back() > s[i]){
                k--;
                ans.pop_back();
            }
            ans.push_back(s[i]);
        }
        
        while( k > 0 && s.size() >0){
            k--;
            ans.pop_back();
        }
        int i ;
        for(i = 0 ; i< ans.size() ; i++ ){
            if(ans[i] != '0') break;
        }
        
        ans.erase(0 , i);
        if(ans == ""){
            return "0";
        }
        return ans;
    }
};