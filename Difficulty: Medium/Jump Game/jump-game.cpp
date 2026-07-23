class Solution {
  public:
    // Function to check if we can reach the last index from 0th index.
    bool canReach(vector<int> &arr) {
        // code here
         int reach = 0 ;
        int n = arr.size();
        for(int i = 0 ;i<arr.size() ; i++){
            if(i > reach){
                return false;
            }
            reach = max(reach , i+ arr[i]);
        }

        return true;
    }
};