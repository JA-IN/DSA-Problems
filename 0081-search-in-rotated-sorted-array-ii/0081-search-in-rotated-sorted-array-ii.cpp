class Solution {
public:
    char check_sorted(vector<int>& nums , int left , int mid , int right){
        char half ;
        if(nums[left] <= nums[mid]){
            half= 'A';
        }
        else{
            half = 'B';
        }
        return half;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0 , right = n-1;
        while(left <= right){
            if(nums[left]== target || nums[right] == target){
                return true;
            }
            if(left != right && nums[left] == nums[right]){
                left++ , right--;
                continue;
            }
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                return true;
            }
            char half = check_sorted(nums , left , mid , right);
            if(half == 'A'){
                if(nums[left] <= target && nums[mid] >= target){
                    right = mid -1;
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
        return false;
    }
};