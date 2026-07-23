class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // swap intervals to sort on the basis of end time
        for(int i = 0 ; i < n;i++){
            swap(intervals[i][0] , intervals[i][1]);
        }

        sort(intervals.begin() , intervals.end());
        int count = 0;
        int last_end = intervals[0][0];
        for(int i = 1 ; i< n;i++){
            int curr_start = intervals[i][1];
            int curr_end = intervals[i][0];

            if(last_end > curr_start){
                count++;
            }
            else{
                last_end = curr_end;
            }
        }

        return count;
    }
};