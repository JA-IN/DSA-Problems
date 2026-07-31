class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n ;

        if( exp <0) exp = -exp;
        double ans = 1 ;
        while(exp){

            if(exp & 1){
            ans = ans * x;
            }
            x = x*x;
            
            exp >>=1;
        }
        if(n < 0){
            return 1/ans;
        }
        return ans;
    }
};