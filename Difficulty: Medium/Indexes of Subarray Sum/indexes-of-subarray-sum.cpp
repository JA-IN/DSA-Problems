class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int curr_sum = 0 ;
        unordered_map<int,int>mp;
        mp[0] = 0;
        int n= arr.size();
        for(int i = 0 ; i< arr.size() ; i++){
            curr_sum +=arr[i];
            int req = curr_sum - target ;
            
            if(mp.find(req) != mp.end()){
                int start = mp[req] +1;
                int end = i+1;
                return {start , end};
            }
            
            if(mp.find(curr_sum) == mp.end()){
            mp[curr_sum] = i+1 ;
            }
            
        }
        
        return {-1};
    }
};