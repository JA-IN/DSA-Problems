class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>ans(n ,1);
        
        for(int i = 1 ; i < n; i++){
            if(arr[i] > arr[i-1]){
                ans[i] = ans[i-1] +1;
            }
        }
        
        for(int i = n-2 ; i >=0 ; i--){
            
            if(arr[i] > arr[i+1]){
                int val = ans[i+1]+1;
                
                ans[i] = max(ans[i] , val);
            }
        }
        
        int candies = 0 ;
        for(int i = 0 ; i< n;i++){
            candies +=ans[i];
        }
        
        return candies;
    }
};
