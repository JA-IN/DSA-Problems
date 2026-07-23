class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        vector<vector<int>>ans;
        sort(intervals.begin() , intervals.end() ,[](vector<int>&a , vector<int>&b){
            return a[0] < b[0];
        } );
        ans.push_back({intervals[0][0] , intervals[0][1]});
        int n = intervals.size();
        for(int i = 1 ; i< n ; i++){
            int last_start = ans[ans.size()-1][0];
            int last_end = ans[ans.size()-1][1];

            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];

            if(last_end >= curr_start){
                ans[ans.size()-1][0] = min(last_start ,curr_start);
                ans[ans.size()-1][1] = max(last_end ,curr_end);
            }
            else{
                ans.push_back({curr_start , curr_end});
            }
        }
        return ans;
    }
};