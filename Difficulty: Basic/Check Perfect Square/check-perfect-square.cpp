class Solution {
  public:
    bool isPerfectSquare(int num) {
        // code here
        if(num < 2){
            return true;
        }
        long long low=1,high=num/2;
        
        
        // it is the problem of inary search
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(mid*mid == num){
               return true;
            }
            else if(mid * mid > num){
                high=mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return false;
    }
};