class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
          unordered_map<int,int>freq;
        for(int i = 0 ; i< nums.size() ; i++){
            freq[nums[i]]++;
        }

        priority_queue<pair<int,int>>pq;
        for(auto x : freq){
            pq.push({x.second, x.first});
        }
        vector<int>ans;
        while(k--){
            pair<int,int>element = pq.top();
            pq.pop();
            
            int val = element.second;
            ans.push_back(val);
        }

        return ans;
    }
};