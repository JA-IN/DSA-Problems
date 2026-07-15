class Solution {
public:
    char check_sorted(vector<int>& nums ,int left , int mid , int right){
        if(nums[left] <= nums[mid]){
            return 'A';
        }
       
            return 'B';
        
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0 , right = n-1;
        while(left <= right){
            int mid = left +(right - left)/2;
            if(nums[mid] == target){
                return mid;
            }
            // check which half is sorted
           char half = check_sorted( nums ,left , mid , right);
           if(half == 'A'){
            // check whether the target lies with in sorted part or not
            if(nums[left] <= target && nums[mid] >= target){
                right = mid-1;
            }
            else{
                left = mid +1;
            }
           }
           if(half == 'B'){
            if(nums[mid] <= target && nums[right] >= target){
                left = mid +1;
            }
            else{
                right = mid -1;
            }
           }
        }
        return -1;
    }
};