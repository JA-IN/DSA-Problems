class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0 , right = n-1;
        int MIN = INT_MAX;
        while(left <= right){
            int mid = left + (right - left)/2;
           if(nums[mid] == nums[right]){
            MIN = min(MIN , nums[mid]);
            right--;
           }
           else if(nums[mid] < nums[right]){ // right part sorted then find in left part
            MIN = min(MIN , nums[mid]);
            right = mid-1;
           }
           else if(nums[mid] > nums[right]){  // left part sorted and find in right part 
            MIN = min(MIN , nums[left]);
            left = mid +1;
           }
        }
        return MIN;
    }
};