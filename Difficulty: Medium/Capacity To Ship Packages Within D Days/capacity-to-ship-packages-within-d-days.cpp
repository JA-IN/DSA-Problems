class Solution {
  public:
    bool ispossible(vector<int>& arr, int days, int capacity) {
        int curr_days = 1;
        int curr_cap = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (curr_cap + arr[i] <= capacity) {
                curr_cap += arr[i];
            } else {
                curr_days++;
                if (curr_days > days){
                    return false;
                }
                curr_cap = arr[i];
            }
        }
        return true;
    }
    int leastWeightCapacity(vector<int>& arr, int D) {
        // code here
        int n = arr.size();
        int left = *max_element(arr.begin(), arr.end());
        int right = accumulate(arr.begin(), arr.end(), 0);
        int ans;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (ispossible(arr, D, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};