class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int> q;
        int ans = INT_MAX;
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        q.push_back(0);
        for (int i = 1; i < n + 1; i++) {
            prefix[i] += prefix[i - 1] + nums[i - 1];
        }
        for (int i = 0; i < n + 1; i++) {
            while (!q.empty() && prefix[i] - prefix[q.front()] >= k) {
                ans = min(ans, i - q.front());
                q.pop_front();
            }

            while (!q.empty() && prefix[i] <= prefix[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

    if(ans == INT_MAX){
        return -1;
    }
    return ans;
    }
};