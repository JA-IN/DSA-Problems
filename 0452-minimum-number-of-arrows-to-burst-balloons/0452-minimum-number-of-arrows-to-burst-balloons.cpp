class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin() , points.end() , [](vector<int>&a , vector<int>&b){
            return a[1] < b[1];
        });
        if(points.size() == 0){
            return 0 ;
        }

        int arrows = 1;
        int i = 1 , n = points.size();
        int small_end = points[0][1];

        while( i < n){
            int curr_start = points[i][0];

            if(small_end >= curr_start){
                i++;
            }
            else{
                arrows++;
                small_end = points[i][1];
                i++;
            }
        }

        return arrows;
    }
};