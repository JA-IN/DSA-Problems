class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int left = 0 , right = 0 , ans = INT_MIN ;
        unordered_map<int,int>window;
        int distict = 2;
        
        // it is basically a sliding window problem in which we have to 
        // return longest window in which there should not be more than 
        // 2 distint (different) integers
        
        while(right < n){
            window[arr[right]]++;
            
            while(window.size() > 2){
                window[arr[left]]--;
                if(window[arr[left]] == 0){
                    window.erase(arr[left]);
                }
                left++;
            }
            ans = max(ans , right-left+1);
            right++;
        }
        return ans;
    }
};