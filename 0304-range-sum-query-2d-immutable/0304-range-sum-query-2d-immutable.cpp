class NumMatrix {
public:
    vector<vector<int>>matrix;
    vector<vector<int>>prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i = 0 ; i< matrix.size();i++){
            vector<int>temp;
            for(int j = 0 ; j < matrix[i].size();j++){
                temp.push_back(matrix[i][j]);
            }
            this->matrix.push_back(temp);
        }
        int r = matrix.size() , c= matrix[0].size();
        for(int i = 0  ; i< r+1 ;i++){
            vector<int>temp(c+1 ,0);
            prefix.push_back(temp);
        }
        for(int i = 1 ; i < r+1 ; i++){
           
            for(int j = 1 ; j< c+1 ; j++){
                prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int new_r1 = row1+1 , new_c1 = col1+1 , new_r2 = row2+1 , new_c2 = col2+1;
        int total_sum = this->prefix[new_r2][new_c2];
        int above = this->prefix[new_r1-1][new_c2];
        int left = this->prefix[new_r2][new_c1-1];
        int overlap = this->prefix[new_r1-1][new_c1-1];

        int ans = total_sum - above - left + overlap;

        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */