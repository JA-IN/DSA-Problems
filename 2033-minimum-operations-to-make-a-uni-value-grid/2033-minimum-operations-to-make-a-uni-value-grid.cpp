class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> sorted;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                sorted.push_back(grid[i][j]);
            }
        }
        sort(sorted.begin(), sorted.end());

        int n = sorted.size();
        int mid = sorted[n / 2];
        int ans = 0 ;
        for (int i = 0; i < n; i++) {
            int val = abs(sorted[i] - mid) ;

            if(val % x !=0){
                return -1;
            }
            ans += val/x;
        }

        return ans;
    }
};