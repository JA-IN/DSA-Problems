class Solution {
  public:
  void prev_smaller(vector<int>& histogram, vector<int>& left_smaller) {
        stack<int> s;
        int n = histogram.size();
        for (int i = n-1; i >=0; i--) {
            while (!s.empty() && histogram[s.top()] > histogram[i]) {
                int idx = s.top();
                s.pop();
                int left = i + 1;
                left_smaller[idx] = left;
            }
            s.push(i);
        }
    }
    void next_smaller(vector<int>& histogram, vector<int>& right_smaller) {
        stack<int> s;
        int n = histogram.size();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && histogram[s.top()] > histogram[i]) {
                int idx = s.top();
                s.pop();
                int right = i - 1;
                right_smaller[idx] = right;
            }
            s.push(i);
        }
    }
    int largest_rectangle(vector<int>& histogram) {
        int n = histogram.size();
        vector<int> right_smaller(n, n-1);
        vector<int> left_smaller(n, 0);
        int area = 0;
        next_smaller(histogram, right_smaller);
        prev_smaller(histogram, left_smaller);

        for (int i = 0; i < n; i++) {
            int right = right_smaller[i];
            int left = left_smaller[i];
            int width = right - left + 1;
            int a = histogram[i] * width;
            area = max(area, a);
        }
        return area;
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int row = mat.size(), col = mat[0].size();
        
        vector<int> histogram(col);
        for (int i = 0; i < col; i++) {
            histogram[i] = mat[0][i] ;
        }

        int area = largest_rectangle(histogram);

        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 1) {
                    histogram[j] = histogram[j] + 1;
                } else {
                    histogram[j] = 0;
                }
            }
            int a = largest_rectangle(histogram);
            area = max(area, a);
        }
        return area;
    }
};