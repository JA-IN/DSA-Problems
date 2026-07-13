// Solution 2: Right-to-Left Scan with Third Variable + Monotonic Stack
// Time: O(n), Space: O(n)
// Approach: Scan from right to left. Maintain a monotonic decreasing stack and a
// variable 'third' which tracks the largest valid "2" value found so far.
// When we pop from stack (stack.top() < nums[i]), we update 'third' because we
// found a pair where nums[i] (the "3") > stack.top() (the "2").
// Later, if we encounter nums[i] < third, then nums[i] is "1", third is "2",
// and some earlier element was "3", forming a 132 pattern
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int candidate_2 = INT_MIN;
        stack<int>s;
        for(int i = n-1 ; i >=0 ; i--){
            int curr = nums[i];
            if(curr < candidate_2){
                return true;
            }
           while(!s.empty() && curr > s.top() ){
            
            candidate_2 = s.top();
            s.pop();
           }
            s.push(curr);
        }
        return false;
    }
};