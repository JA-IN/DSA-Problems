class Solution {
  public:
    int atmost(vector<int>&arr , int k ){
        int n = arr.size();
        int left = 0 , right = 0 ;
        unordered_map<int,int>window;
        int ans = 0 ;
        
        while(right < n){
            window[arr[right]]++;
            
            while(window.size() > k){
                window[arr[left]]--;
                if(window[arr[left]] == 0){
                    window.erase(arr[left]);
                }
                left++;
            }
            
            ans += right - left +1 ;
            right++;
        }
        
        return ans;
    }
    int exactlyK(vector<int> &arr, int k) {
        // code here
        // int this problem we cannot calculate the answer directly because
        // we have not return the max/min window (which satisfy condition )but
        // we have to return the number of windows which satisfy the condition.
        // so we will do this by making this problem condition into at max consition
        
        
        int ans = atmost(arr , k) - atmost(arr, k-1);
        return ans;
    }
};