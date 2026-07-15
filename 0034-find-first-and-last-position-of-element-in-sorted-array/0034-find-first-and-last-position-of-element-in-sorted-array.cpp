class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0 , right = n-1;
        if(n == 0){
            return {-1 ,-1};
        }
        // finding lower bound
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] >= target){
                right = mid -1;
            }
            else{
                left = mid+1;
            }
        }
        int lower_bound = left;

        // uppper bound
        left = 0 , right = n-1;
        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] > target){
                right = mid-1;

            }
            else{
                left = mid +1;
            }
        }
        int upper_bound = left-1;
        vector<int>ans;
        
        if(lower_bound <= upper_bound && nums[lower_bound] == nums[upper_bound]){
            ans.push_back(lower_bound);
            ans.push_back(upper_bound);
            return ans;
        }
        return {-1 , -1};

    }
};