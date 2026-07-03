class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int > m;
        vector<int> ans;
        for(int i =0;i<nums.size();i++){
            int req_no = target - nums[i];
            if(m.find(req_no) != m.end()){
                ans.push_back(m[req_no]);
                ans.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return ans ;
    }
};