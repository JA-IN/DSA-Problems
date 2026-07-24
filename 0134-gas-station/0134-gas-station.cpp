class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
       
        int i = 0, start = 0;
        int tank = 0 , total = 0;
        while (i < n) {
            int diff = gas[i] - cost[i];

            tank += diff;
            total +=diff;

            if(tank < 0){
                start = i+1;
                tank = 0 ;
            }
            i++;
        }
        
        if(total < 0) return -1 ;
        
        return start ;
    }
};