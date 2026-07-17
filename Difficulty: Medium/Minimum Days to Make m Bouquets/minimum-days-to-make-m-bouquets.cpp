class Solution {
  public:
    bool ispossible(vector<int>& arr, int k, int m , int days){
        int flowers = 0 , bouquets =0;
        for(int i = 0 ; i< arr.size();i++){
            if(arr[i] <= days){
                flowers++;
                
                if(flowers == k){
                    bouquets++;
                    flowers =0;
                }
            }
            else{
                flowers = 0;
            }
            
            if(bouquets >= m){
                return true;
            }
        }
        return false;
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int left = *min_element(arr.begin() , arr.end());
        int right = *max_element(arr.begin() , arr.end());
        int ans = -1;
        
        while(left <= right){
            int mid = left + ( right - left)/2;
            
            if(ispossible(arr , k , m , mid )){
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