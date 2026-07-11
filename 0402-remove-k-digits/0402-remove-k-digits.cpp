class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size();
        if(k == n){
            return "0";
        }
        stack<char>s;
        for(int i = 0 ; i< n ; i++){
            while(!s.empty() && k && s.top() > nums[i]){
                k--;
                s.pop();
            }
            s.push(nums[i]);
        }
        while(k && !s.empty()){
            k--;
            s.pop();
        }

        string ans="";
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin() , ans.end());
        int idx = 0 ;

        while(idx < n && ans[idx] == '0'){
            idx++;
        }
        string result = ans.substr(idx);
        if(result == ""){
            return "0";
        }
        return result;

    }
};