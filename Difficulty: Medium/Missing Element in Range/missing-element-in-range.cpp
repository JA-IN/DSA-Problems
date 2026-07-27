class Solution {
  public:
    vector<int> missingRange(vector<int>& arr, int low, int high) {
        // code here
        map<int,int>mp;
        for(int i = low ; i<= high ; i++){
            mp[i] = 0 ;
        }
        
        for(int i = 0 ; i< arr.size();i++){
            mp[arr[i]]++;
        }
        vector<int>ans;
        for(auto it : mp){
            if(it.second == 0){
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};