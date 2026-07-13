class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int candidate_2 = INT_MIN;
        stack<int>s;
        for(int i = n-1 ; i >=0 ; i--){
            int curr = nums[i];
            if(curr < candidate_2){
                return true;
            }
           while(!s.empty() && curr > s.top() ){
            
            candidate_2 = s.top();
            s.pop();
           }
            s.push(curr);
        }
        return false;
    }
};