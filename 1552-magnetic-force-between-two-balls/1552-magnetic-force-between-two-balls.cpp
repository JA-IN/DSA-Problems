class Solution {
public:
    bool ispossible(vector<int>& position, int m , int distance){
        int curr_ball = 1 ;
        int lastposition = position[0] ;
        
        for(int i = 1 ; i< position.size();i++){
            
            if(position[i] - lastposition >= distance){
                lastposition = position[i];
                curr_ball++;
            }
            if(curr_ball == m){
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int left = 1;
        int n = position.size();
        sort(position.begin() , position.end());
        int right = position[n-1] - position[0];
        int ans = 0 ;
        while(left <= right){
            int mid = left + ( right - left)/2;

            if(ispossible(position , m , mid)){
                ans = mid ;
                left = mid +1;
            }
            else{
                right = mid -1;
            }
        }
        return ans;
    }
};