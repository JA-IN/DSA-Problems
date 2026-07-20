class Solution {
public:
    double calculate_madian(vector<int>& nums1, vector<int>& nums2){
        int n1=nums1.size() , n2 = nums2.size();
        int left = 0 , right = n1;
        double ans ;
        while(left <= right){
            int partitionA = left + (right - left)/2;

            int left_partition = (n1+n2+1)/2;

            int partitionB = left_partition - partitionA;

            int AL = (partitionA==0)?INT_MIN:nums1[partitionA-1];
            int AR = (partitionA==n1)?INT_MAX:nums1[partitionA];

            int BL = (partitionB==0)?INT_MIN:nums2[partitionB-1];
            int BR = (partitionB==n2)?INT_MAX:nums2[partitionB];

            if(AL <= BR && BL <= AR){
                int check = (n1+n2)%2;
                if(check == 0){
                    ans = (max(AL,BL)+min(AR,BR))/2.0;
                    break;
                }
                else{
                    ans = max(AL,BL);
                    break;
                }
            }
            else if(AL > BR){
                right = partitionA -1;
            }
            else{
                left = partitionA + 1;
            }
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size() , n2 = nums2.size();
        double ans ;
        if(n1 <= n2){
            ans = calculate_madian(nums1 , nums2);
        }else{
             ans = calculate_madian(nums2 , nums1);
        }
        return ans;
    }
};