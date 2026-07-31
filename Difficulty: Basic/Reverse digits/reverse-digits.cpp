class Solution {
  public:
    int reverseDigits(int n) {
        // Code here
        int ans = 0 ;
        while(n){
            int digit = n % 10;
            n = n / 10;
            
            // overflow condition 
            
            if(ans > INT_MAX/10 || ans == INT_MAX/10 && digit >7 ){
                return 0 ;
            }
            
            // underflow condition 
            
            if(ans < INT_MIN / 10 || ans == INT_MIN/10 && digit < -8 ){
                return 0 ;
            }
            
            ans = ans * 10 + digit;
            
        }
        
        return ans;
    }
};