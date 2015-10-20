class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> umap;
        unordered_map<string, int> strmap;
        int idx = 0;
        istringstream in(str);
        for (string sub; in >> sub; idx++) {
            if (idx == pattern.size() || umap[pattern[idx]] != strmap[sub])
                return false;
            umap[pattern[idx]] = strmap[sub] = idx + 1;
        }
        return idx == pattern.size();
    }
};
