class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        long long ans = 0;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[i] < arr[s.top()]) {
                int idx = s.top();
                s.pop();

                if (s.empty()) {
                    int right = i - idx;
                    int left = idx - (-1);
                    long long a = (long long)arr[idx] * right * left;
                    a %= MOD;
                    ans = (ans + a) % MOD;

                } else {
                    int right = i - idx;
                    int left = idx - s.top();
                    long long a = (long long)arr[idx] * right * left;
                    a %= MOD;
                ans = (ans + a) % MOD;
                    
                }
                
            }
            s.push(i);
        }
        while (!s.empty()) {
            int idx = s.top();
            s.pop();
            if (s.empty()) {
                int right = n - idx;
                int left = idx - (-1);
                long long a = (long long)arr[idx] * right * left;
                    a %= MOD;
                    ans = (ans + a) % MOD;

            } else {
                int right = n - idx;
                int left = idx - s.top();
                long long a = (long long)arr[idx] * right * left;
                    a %= MOD;
                ans = (ans + a) % MOD;
                    
            }
            
        }
        return ans % MOD;
    }
};