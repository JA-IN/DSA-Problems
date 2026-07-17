class Solution {
public:
    bool ispossible(vector<int>& bloomDay, int m, int k, int days) {
        int bouquets = 0, flowers = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
            if(bouquets >= m){
                return true;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int ans  = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (ispossible(bloomDay, m, k, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};