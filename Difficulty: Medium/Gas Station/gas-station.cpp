class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int n = gas.size();
        int tank = 0 , total = 0 ;
        int start = 0 ;
        
        for(int i = 0 ; i< n;i++){
            
            int diff = gas[i] - cost[i];
            
            tank += diff;
            total +=diff;
            
            if(tank < 0){
                start = i+1;
                tank = 0 ;
            }
        }
        
        if(total < 0) return -1;
        
        return start;
    }
};