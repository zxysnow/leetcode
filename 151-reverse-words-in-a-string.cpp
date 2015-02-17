class Solution {
public:
    void reverseWords(string &s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                string t = "";
                while (i < s.size() && s[i] != ' ')
                    t += s[i++];
                ans = t + ' ' + ans;
                i--;
            }
        }
        s = ans.substr(0, ans.size() - 1);
    }
};
