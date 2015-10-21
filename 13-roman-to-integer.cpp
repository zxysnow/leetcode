class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int v = find(s[i]);
            if (i + 1 < s.size() && v < find(s[i + 1])) {
                ans -= v;
            } else {
                ans += v;
            }
        }
        return ans;
    }
private :
    int find(char c) {
        switch (c) {
            case 'I':   return 1;
            case 'V':   return 5;
            case 'X':   return 10;
            case 'L':   return 50;
            case 'C':   return 100;
            case 'D':   return 500;
            case 'M':   return 1000;
            default:    return 0;
        }
    }
};
