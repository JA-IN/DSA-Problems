class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0 ;
        int n = nums.size();
        int reach = 0 ;

        if(n==1) return 0 ;
        int curr_end = 0 , farthest = 0 ;
        for(int i = 0 ; i< n-1 ; i++){
            farthest = max(farthest , i+nums[i]);
           
           if(i == curr_end){
            jumps++;
            curr_end = farthest;
           }
        }            

        return jumps;
    }
};