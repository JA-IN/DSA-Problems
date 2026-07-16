class Solution {
  public:
    bool valid(vector<int>& arr, int k , int curr_k){
        int curr_h = 0 ;
        for(int i = 0 ; i< arr.size() ; i++){
            curr_h += arr[i]/curr_k;
            if(arr[i]%curr_k){
                curr_h += 1;
            }
            if(curr_h > k){
                return false;
            }
        }
        return true;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        int Max_k = *max_element(arr.begin() , arr.end());
        
        int left = 1 , right = Max_k;
        int ans = Max_k;
        while(left <= right){
            int mid = left + ( right - left)/2;
            
            if(valid(arr , k , mid)){
                ans = mid ;
                right = mid -1;
            }
            else{
                left = mid +1;
            }
            
        }
        return ans;
    }
};