class Solution {
  public:
    bool reachesOne(int n) {
        // code here
        unordered_set<int>seen;
        
        while(n!= 1 && !seen.count(n)){
            seen.insert(n);
            int new_n = 0 ;
            
            while(n){
                int digit = n % 10;
                new_n += digit * digit;
                n = n / 10;
            }
            n = new_n;
        }
        
        return n==1;
    }
};