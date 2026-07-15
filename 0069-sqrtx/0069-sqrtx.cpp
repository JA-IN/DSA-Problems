class Solution {
public:
    int mySqrt(int x) {
        // we will solve this using binary search
        if(x == 1){
            return 1;
        }
        int search_space = x/2;
        int left = 0 , right = search_space -1;
        while(left <= right){
            int mid = left + (right - left)/2;
            long long digit = mid+1;
            long long value = digit * digit;
            if(value > x){
                right = mid-1;
            }
            else{
                left = mid +1;
            }
        }
        return left;
    }
};