class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ans;
        unordered_map<string, int> m;
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            if (m.count(key)) {
                ans.push_back(strs[i]);
                int pos = m[key];
                if (pos != -1) {
                    ans.push_back(strs[pos]);
                    m[key] = -1;
                }
            } else {
                m[key] = i;
            }
        }
        return ans;
    }
};
