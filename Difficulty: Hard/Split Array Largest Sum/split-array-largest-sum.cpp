class Solution {
  public:
    bool ispossible(vector<int>& arr, int k , int min_val){
        int curr_k = 1 ;
        long long sum = 0 ;
        for(int i = 0 ; i< arr.size(); i++){
            if(sum + arr[i] <= min_val){
                sum += arr[i];
            }
            else{
                curr_k++;
                sum = arr[i];
            }
            if(curr_k > k) return false;
        }
        return true;
    }
    int splitArray(vector<int>& arr, int k) {
        // code here
       long long left = *max_element(arr.begin() , arr.end());
        long long right = accumulate(arr.begin() , arr.end() ,0);
        long long ans= 0 ;
        while(left <= right){
            long long mid = left + (right - left)/2;

            if(ispossible(arr , k , mid)){
                ans = mid;
                right = mid -1;
            }
            else{
                left =  mid +1 ;
            }
        }
        return ans;
    }
};