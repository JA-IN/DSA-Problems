class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        int left = 0, right = 0;
        unordered_map<char, int> window;
        unordered_map<char, int> need;
        int required = n2, ans = INT_MAX, start, end;
        for (int i = 0; i < n2; i++) {
            window[t[i]] = 0;
            need[t[i]]++;
        }
        while (right < n1) {
            if (need.find(s[right]) != need.end()) {
                // adding elements in window and update required variable
                window[s[right]]++;
                if (window[s[right]] <= need[s[right]]) {
                    required--;
                }

                while (required == 0) {

                    if (ans > right - left + 1) {
                        ans = right - left + 1;
                        start = left;
                        end = right;
                    }
                    // removing element in window & update required variable
                    if (need.find(s[left]) != need.end()) {
                        window[s[left]]--;
                        if (window[s[left]] < need[s[left]]) {
                            required++;
                        }
                    }
                    
                    left++;
                }
            }

            right++;
        }
        string result = "";
        if(ans == INT_MAX){
            return result;
        }
        for(int i = start ; i <= end ; i++){
            result +=s[i];
        }
        return result;
    }
};