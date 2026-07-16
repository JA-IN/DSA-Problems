class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // code here
         int n = arr.size();
        int left = 0 , right = n - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;

            // downhill case ( we encounter a downhill)
            if (arr[mid] > arr[mid + 1]) {

                right = mid;

            } else if (arr[mid] < arr[mid + 1]) {

                left = mid + 1;
            }
        }
        return left;
    }
};