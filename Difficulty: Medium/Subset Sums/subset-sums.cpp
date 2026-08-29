class Solution {
  public:
    void solve(int index , int sum , vector<int>&arr , vector<int>&ans){
        if(index == arr.size()){
            ans.push_back(sum);
            return ;
        }
        
        solve(index+1 , sum+arr[index] , arr , ans);
        
        solve(index+1 , sum , arr , ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>ans;
        
        int n = arr.size();
       solve(0 , 0 , arr , ans);
       
       return ans;
    }
};