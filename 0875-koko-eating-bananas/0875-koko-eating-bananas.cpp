class Solution {
public:
    bool valid(vector<int>& piles, int h , int curr_k){
        int n = piles.size();
        int curr_h = 0;
        for(int i = 0 ; i< n ; i++){
            curr_h += piles[i]/curr_k;
            if(piles[i] % curr_k){
                curr_h +=1;
            }
            if(curr_h > h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int Max_k = *max_element(piles.begin() , piles.end());
        int left = 1 , right = Max_k;
        int ans = Max_k;
        while(left <= right){
            int mid = left + (right - left)/2;

            if(valid(piles , h , mid)){
                ans = mid;
                right= mid -1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};