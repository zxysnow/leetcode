class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return "";
        for (int i = 0; i < strs[0].size(); i++) {
            for (int k = 1; k < strs.size(); k++) {
                if (strs[k].size() < i || strs[k][i] != strs[0][i])
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};
