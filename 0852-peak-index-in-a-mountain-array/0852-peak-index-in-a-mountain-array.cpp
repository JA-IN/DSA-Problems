class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
      //it is the problem of the upper bound 
      int n = arr.size();
      int left = 0 , right = n-1;
      while(left < right){
        int mid = left + ( right - left)/2;
        if(arr[mid] > arr[mid+1]){
            right = mid;
        }
        else if(arr[mid] < arr[mid+1]){
            left = mid +1;
        }
      }  
      return left;
    }
};