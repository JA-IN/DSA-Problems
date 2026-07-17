class Solution {
  public:
    bool ispossible(vector<int>& arr, int k , int divisor){
        int curr_cap = 0 ;
        for(int i = 0 ; i< arr.size();i++){
            curr_cap += arr[i]/divisor;
            if(arr[i]%divisor){
                curr_cap += 1;
            }
            if(curr_cap > k){
                return false;
            }
        }
        return true;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int left = 1 ;
        int right = *max_element(arr.begin() , arr.end());
        int ans ;
        while(left <= right){
            int mid = left + ( right - left)/2;
            
            if(ispossible(arr , k , mid)){
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
