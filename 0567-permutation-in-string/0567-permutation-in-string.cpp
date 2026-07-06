class Solution {
public:
    bool sameFrequency(vector<int>& window, vector<int>& need) {
        for (int i = 0; i < 26; i++) {
            if (window[i] != need[i]) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> need(26, 0);
        vector<int> window(26, 0);

        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) {
            return false;
        }
        for (int i = 0; i < n1; i++) {
            need[s1[i] - 'a']++;
        }

        for (int i = 0; i < n1; i++) {
            window[s2[i] - 'a']++;
        }

        if (sameFrequency(window, need)) {
            return true;
        }
        int right =
            n1; // starting point of the where right should point after 1 window
        for (int i = right; i < n2; i++) {
            int remove = s2[i - n1] - 'a';
            int add = s2[i] - 'a';

            window[remove]--;
            window[add]++;
            if (sameFrequency(window, need)) {
                return true;
            }
        }
        return false;
    }
};