class Solution {
  public:
    char check_sorted(vector<int>& arr , int left , int mid , int right){
        if(arr[left] <= arr[mid]){
            return 'A';
        }
        return 'B';
    }
    int findMin(vector<int>& arr) {
        // code here
        int n = arr.size();
        int left = 0 , right = n-1;
        int MIN = INT_MAX;
        while(left <= right){
            int mid = left + (right - left)/2;
            MIN = min(MIN , arr[mid]);

            char half = check_sorted(arr , left , mid , right );
            if(half == 'A'){
                int curr_min = arr[left];
                MIN = min(MIN , curr_min);
                left = mid +1;
            }
            if(half == 'B'){
                int curr_min = arr[mid];
                MIN = min(MIN , curr_min);
                right = mid -1;
            }
        }
        return MIN;
    }
};