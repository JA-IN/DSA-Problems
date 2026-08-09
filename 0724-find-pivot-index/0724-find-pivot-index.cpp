class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i - 1] + nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {

                int left = 0;
                int right = nums[nums.size() - 1] - nums[i];
                if (left == right) {
                    return i;
                } 
                }else if (i == nums.size() - 1) {
                    int left = nums[i - 1];
                    int right = 0;
                    if (left == right) {
                        return i;
                    }
                } else {
                    int left = nums[i - 1];
                    int right = nums[nums.size() - 1] - nums[i];
                    if (left == right) {
                        return i;
                    }
                }
        }

        return -1;
    }
};