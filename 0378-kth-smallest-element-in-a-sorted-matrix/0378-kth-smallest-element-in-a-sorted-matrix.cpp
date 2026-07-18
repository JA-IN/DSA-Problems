class Solution {
public:
    int countLessEqual(vector<vector<int>>& matrix, int mid) {
        
        int n = matrix.size();
        int count = 0;
        int i = 0, j = n - 1;
        while (i < n && j >= 0) {
            if (matrix[i][j] <= mid) {
                count += j + 1;
                i++;
            } else {
                j--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        int ans ;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            int cnt = countLessEqual(matrix, mid);

            if (cnt >= k) {
                // mid could be the answer
                ans = mid;
                right = mid - 1;
            } else {
                // Need a larger value
                left = mid + 1;
            }
        }
        return ans;
    }
};