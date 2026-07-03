class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin() , people.end());
        int left = 0 , n = people.size();
        int right = n -1;
        int boats = 0 ;
        while( left <= right){
            if(people[left] + people[right] <= limit){
                left++ , right--;
                boats++;
            }
            else{
                boats++;
                right--;
            }
        }
        if(left == right){
            boats++;
        }
        return boats;
    }
};