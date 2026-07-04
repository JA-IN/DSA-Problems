class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxavg = 0 , avg ;
        double sum = 0 ;
        for(int i = 0 ; i< k ; i++){
                sum +=nums[i];
        }
        avg = sum / k ;
        maxavg = avg ;
        for(int i = k ; i < n ;i++){
            sum = sum - nums[i-k] + nums[i];
            avg = sum / k;

            if(avg > maxavg) maxavg = avg;
        }

        return maxavg;
    }
};