class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            bool alive = true;
            while (!s.empty() && asteroids[s.top()] > 0 && asteroids[i] < 0) {

                if (abs(asteroids[s.top()]) == abs(asteroids[i])) {
                    alive = false;
                    s.pop();
                    break;
                } else if (abs(asteroids[s.top()]) > abs(asteroids[i])) {
                    alive = false;
                    break;
                } else {
                    s.pop();
                }
            }
            if(alive == true) s.push(i);
            
        }
        if (s.empty()) {
            return {};
        }
        while (!s.empty()) {
            ans.push_back(asteroids[s.top()]);
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};