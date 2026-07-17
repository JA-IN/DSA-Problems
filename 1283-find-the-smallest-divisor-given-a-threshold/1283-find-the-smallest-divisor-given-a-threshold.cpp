class Solution {
public:
    bool ispossible(vector<int>& nums, int threshold , int divisor){
        int curr_thresh = 0 ;
        for(int i = 0 ; i< nums.size();i++){
            curr_thresh += nums[i]/divisor;
            if(nums[i] % divisor) {
                curr_thresh += 1;
            }
            if(curr_thresh > threshold){
                return false;
            }
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int left = 1 ;
        int right = *max_element(nums.begin() , nums.end());
        int ans ;
        while(left <= right){
            int mid = left + ( right - left)/2;

            if(ispossible(nums , threshold , mid)){
                ans = mid ;
                right = mid -1;
            }
            else{
                left = mid +1 ;
            }
        }
        return ans;
    }
};