class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while (--n) {
            string t = "";
            int cnt = 1;
            s += '#';
            for (int i = 1; i < s.size(); i++) {
                if (i < s.size() && s[i] == s[i - 1]) {
                    while (i < s.size() && s[i] == s[i - 1]) {
                        i++;
                        cnt++;
                    }
                }
                t += char('0' + cnt);
                t += s[i - 1];
                cnt = 1;
            }
            s = t;
        }
        return s;
    }
};
