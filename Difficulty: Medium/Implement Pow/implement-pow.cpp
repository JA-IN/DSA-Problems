class Solution {
  public:
    double power(double b, int e) {
        // code here
        long long exp = e ;

        if( exp <0) exp = -exp;
        double ans = 1 ;
        while(exp){

            if(exp & 1){
            ans = ans * b;
            }
            b = b*b;
            
            exp >>=1;
        }
        if(e < 0){
            return 1/ans;
        }
        return ans;
    }
};