class Solution {
  public:
    int minOps(vector<int>& arr) {
        // code here
        int min = *min_element(arr.begin() , arr.end());
        int ans = 0 ;
        
        for(int i = 0 ; i< arr.size() ; i++){
            ans += arr[i] - min ;
        }
        
        return ans;
    }
};