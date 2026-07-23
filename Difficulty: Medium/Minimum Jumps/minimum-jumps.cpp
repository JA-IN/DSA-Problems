class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        int jumps = 0 , curr_end = 0 , farthest = 0 ;
        if(arr[0] == 0){
            return -1;
        }
        
        for(int i = 0 ; i< n-1 ; i++){
            
            
            farthest = max(farthest , i+arr[i]);
            
            if(i == curr_end){
                jumps++;
                curr_end = farthest;
            }
        }
        
        if(curr_end >= n-1) return jumps;
        
        return -1; 
        
    }
};
