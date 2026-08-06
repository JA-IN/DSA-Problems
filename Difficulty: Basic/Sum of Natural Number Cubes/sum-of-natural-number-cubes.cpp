class Solution {
  public:
    int sumOfSeries(int n) {
        // code here
        int ans = 0 ;
        for(int i = 1 ; i <= n ; i++){
            ans += i*i*i;
        }
        
        return ans;
    }
};