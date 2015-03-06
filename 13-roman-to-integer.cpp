class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        string str = "";
        for (int i = 0; i < s.size(); i++) {
            int v = find(str + s[i]);
            if (i + 1 < s.size()) {
                int p = find(str + s[i] + s[i + 1]);
                if (p != -1) {
                    v = p;
                    i++;
                }
            }
            ans += v;
        }
        return ans;
    }
private :
    int find(string s) {
        string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};    
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        for (int i = 0; i < 13; i++)
            if (symbol[i] == s)
                return value[i];
        return -1;
    }
};
