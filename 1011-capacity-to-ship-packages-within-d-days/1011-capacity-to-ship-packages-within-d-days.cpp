class Solution {
public:
    bool ispossible(vector<int>& weights, int days, int capacity) {
        int curr_days = 1;
        int curr_cap = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (curr_cap + weights[i] <= capacity) {
                curr_cap += weights[i];
            } else {
                curr_days++;
                if (curr_days > days){
                    return false;
                }
                curr_cap = weights[i];
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int ans;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (ispossible(weights, days, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};