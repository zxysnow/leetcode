class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> m(260, -1);
        vector<bool> in(260, false);
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == -1) {
                m[s[i]] = t[i];
                if (in[t[i]])
                    return false;
                in[t[i]] = true;
            } else if (m[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};
