class Solution {
public:
    bool ispossible(vector<int>& time, int totalTrips , long long curr_time){
        long long trips = 0 ;
        for(int i = 0 ; i< time.size() ; i++){
            trips += curr_time/time[i];
            if(trips >= totalTrips){
                return true;
            }
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long left = *min_element(time.begin() , time.end()) ;
        long long right = (long long)left * totalTrips;
        long long ans = 0 ;
        while(left <= right){
            long long mid = left + ( right - left)/2;

            if(ispossible(time , totalTrips , mid)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }

        return ans;

    }
};