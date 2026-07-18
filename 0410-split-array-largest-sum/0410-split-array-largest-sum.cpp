class Solution {
public:
    bool ispossible(vector<int>& nums, int k , int min_val){
        int curr_k = 1 ;
        long long sum = 0 ;
        for(int i = 0 ; i< nums.size(); i++){
            if(sum + nums[i] <= min_val){
                sum += nums[i];
            }
            else{
                curr_k++;
                sum = nums[i];
            }
            if(curr_k > k) return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        long long left = *max_element(nums.begin() , nums.end());
        long long right = accumulate(nums.begin() , nums.end() ,0);
        long long ans= 0 ;
        while(left <= right){
            long long mid = left + (right - left)/2;

            if(ispossible(nums , k , mid)){
                ans = mid;
                right = mid -1;
            }
            else{
                left =  mid +1 ;
            }
        }
        return ans;
    }
};