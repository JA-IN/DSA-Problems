class Solution {
public:
    string one(int r) {
        string ans = "";
        if (r == 0) {
            return "";
        }
        if (r == 1) {
            return "I";
        } else if (r == 2) {
            return "II";
        } else if (r == 3) {
            return "III";
        } else if (r == 4) {
            return "IV";
        } else if (r == 5) {
            return "V";
        } else if (r == 6) {
            return "VI";
        } else if (r == 7) {
            return "VII";
        } else if (r == 8) {
            return "VIII";
        } else {
            return "IX";
        }
    }
    string ten(int r) {
        string ans = "";
        if (r == 0) {
            return "";
        }
        if (r == 1) {
            return "X";
        } else if (r == 2) {
            return "XX";
        } else if (r == 3) {
            return "XXX";
        } else if (r == 4) {
            return "XL";
        } else if (r == 5) {
            return "L";
        } else if (r == 6) {
            return "LX";
        } else if (r == 7) {
            return "LXX";
        } else if (r == 8) {
            return "LXXX";
        } else {
            return "XC";
        }
    }
    string hundered(int r) {
        string ans = "";
        if (r == 0) {
            return "";
        }
        if (r == 1) {
            return "C";
        } else if (r == 2) {
            return "CC";
        } else if (r == 3) {
            return "CCC";
        } else if (r == 4) {
            return "CD";
        } else if (r == 5) {
            return "D";
        } else if (r == 6) {
            return "DC";
        } else if (r == 7) {
            return "DCC";
        } else if (r == 8) {
            return "DCCC";
        } else {
            return "CM";
        }
    }

    string thousand(int r) {
        string ans = "";
        if (r == 1) {
            return "M";
        } else if (r == 2) {
            return "MM";
        } else {
            return "MMM";
        }
    }

    string intToRoman(int num) {
        string ans = "";
        int i = 0;
        while (num > 0) {
            int r = num % 10;
            if (i == 0) {
                string temp = one(r);
                reverse(temp.begin(), temp.end());
                ans += temp;
            } else if (i == 1) {
                string temp = ten(r);
                reverse(temp.begin(), temp.end());
                ans += temp;
            } else if (i == 2) {
                string temp = hundered(r);
                reverse(temp.begin(), temp.end());
                ans += temp;
            } else if (i == 3) {
                string temp = thousand(r);
                reverse(temp.begin(), temp.end());
                ans += temp;
            }
            num = num / 10;
            i++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};