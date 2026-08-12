class Solution {
  public:
  
    int get_ans(vector<int>&arr , int f , int l){
        int sum = 0 ;
        for(int i = f ; i<=l ; i++){
            sum +=arr[i];
        }
        return sum;
    }
    vector<int> rangeSumQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        vector<int>ans;
        for(int i = 0 ; i< queries.size();i++){
            if(queries[i][0] == 1){
                int f = queries[i][1];
                int l = queries[i][2];
                ans.push_back(get_ans(arr , f , l));
            }
            else{
                int idx = queries[i][1];
                int val = queries[i][2];
                arr[idx] = val;
            }
        }
        
        return ans;
    }
};