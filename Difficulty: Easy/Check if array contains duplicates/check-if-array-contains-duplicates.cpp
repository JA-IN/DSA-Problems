class Solution {
  public:
    bool checkDuplicates(vector<int> &arr) {
        // code here
        unordered_map<int,int>mp;
        for(int i = 0 ; i < arr.size() ; i++){
            if(mp[arr[i]]) return true;

            mp[arr[i]] =1;
        }

        return false;
    }
};
