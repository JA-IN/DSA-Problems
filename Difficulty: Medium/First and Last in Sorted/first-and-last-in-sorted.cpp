class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int left = 0 , right = n-1;
        
        // lower bound 
        while(left <= right){
            int mid = left + (right - left)/2;
            
            if(arr[mid] >= x){
                right = mid-1;
            }
            else{
                left = mid +1;
            }
        }
        int lower_bound = left;
        left = 0 , right = n-1;
         while(left <= right){
            int mid = left + (right - left)/2;
            
            if(arr[mid] > x){
                right = mid-1;
            }
            else{
                left = mid +1;
            }
        }
        int upper_bound = left-1;
        if(lower_bound == n || arr[lower_bound] != x){
            return {-1 , -1};
        }
        
        vector<int>ans;
        ans.push_back(lower_bound);
        ans.push_back(upper_bound);
        return ans;
    }
};