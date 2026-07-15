class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        if(n < 2){
            return n;
        }
        long long low=1,high=n/2;
        long long ans=0;
        
        // it is the problem of upper bound
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(mid*mid<=n){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};