class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        // this is exact same peoblem of longest repeating characteer
        // replacement
        int n = arr.size();
        int left = 0, right = 0 ,ans = INT_MIN;
        unordered_map<int, int> window;
        window[1] = 0, window[0] = 0;
        int maxfree = 0;
        while (right < n) {
            window[arr[right]]++;
            int window_length = right - left + 1;

            if (window_length - window[1] > k) {
                window[arr[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);

            right++;
        }
        return ans;
    }
};
