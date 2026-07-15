class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
          int n = arr.size();
        int left = 0 , right = n-1;
        // lower bound problem
        while(left <= right){
            int mid = left + ( right - left)/2;
            if(arr[mid]  >= k){
                right = mid -1;
            }
            else{
                left = mid+1;
            }
        }
        return left ;
    }
};