class Solution {
  public:
    char check_sorted(vector<int>& arr , int left , int mid , int right){
        char half ;
        if(arr[left] <= arr[mid]){
            half= 'A';
        }
        else{
            half = 'B';
        }
        return half;
    }
    bool search(vector<int>& arr, int key) {
        // Code here
        int n = arr.size();
        int left = 0 , right = n-1;
        while(left <= right){
            if(arr[left]== key || arr[right] == key){
                return true;
            }
            if(left != right && arr[left] == arr[right]){
                left++ , right--;
                continue;
            }
            int mid = left + (right - left)/2;
            if(arr[mid] == key){
                return true;
            }
            char half = check_sorted(arr , left , mid , right);
            if(half == 'A'){
                if(arr[left] <= key && arr[mid] >= key){
                    right = mid -1;
                }
                else{
                    left = mid +1;
                }
            }
            if(half == 'B'){
                if(arr[mid] <= key && arr[right] >= key){
                    left = mid +1;
                }
                else{
                    right = mid -1;
                }
            }
        }
        return false;
    }
};