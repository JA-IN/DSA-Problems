class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n , 0);
        stack<int>s;
        for(int i = 0 ; i< n ; i++){

            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                int right = i;
                int left = s.top();
                ans[s.top()] = right - left ;
                s.pop();
            }
            s.push(i);
        }

        return ans;
    }
};