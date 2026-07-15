class Solution {
public:
    char check_sorted(vector<int>& nums , int left , int mid , int right){
        if(nums[left] <= nums[mid]){
            return 'A';
        }
        return 'B';
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0 , right = n-1;
        int MIN = INT_MAX;
        while(left <= right){
            int mid = left + (right - left)/2;
            MIN = min(MIN , nums[mid]);

            char half = check_sorted(nums , left , mid , right );
            if(half == 'A'){
                int curr_min = nums[left];
                MIN = min(MIN , curr_min);
                left = mid +1;
            }
            if(half == 'B'){
                int curr_min = nums[mid];
                MIN = min(MIN , curr_min);
                right = mid -1;
            }
        }
        return MIN;
    }
};