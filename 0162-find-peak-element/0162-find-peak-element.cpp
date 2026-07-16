class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0 , right = n - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;

            // downhill case ( we encounter a downhill)
            if (nums[mid] > nums[mid + 1]) {

                right = mid;

            } else if (nums[mid] < nums[mid + 1]) {

                left = mid + 1;
            }
        }
        return left;
    }
};