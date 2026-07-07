class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int ,int>window;
        int n = fruits.size();
        int left = 0 , right = 0 ;
        int baskets = 2;
        int ans = INT_MIN;
        while(right < n){
            window[fruits[right]]++;

            while(window.size() > baskets){
                window[fruits[left]]--;
                if(window[fruits[left]] == 0){
                    window.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans , right - left +1);
            right++;
        }
        return ans;
    }
};