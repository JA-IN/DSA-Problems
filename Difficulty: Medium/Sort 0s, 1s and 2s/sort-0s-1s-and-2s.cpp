class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int low = 0 ;
        int n = arr.size();
        int high = n;
        int mid = low ;
        
        while(mid < high){
            if(arr[mid] == 0){
                swap(arr[low] , arr[mid]);
                low++, mid++;
            }
            else if( arr[mid] == 1){
                mid++;
            }
            else{
                swap(arr[mid] , arr[high-1]);
                high--;
            }
        }
    }
};