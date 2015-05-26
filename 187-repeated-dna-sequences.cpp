class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> umap;
        vector<string> ans;
        if (s.size() < 10)
            return ans;
        for (int i = 0; i <= s.size() - 10; i++) {
            string sub = s.substr(i, 10);
            int h = hash(sub);
            if (umap.count(h) && umap[h] == 1) {
                ans.push_back(sub);
            }
            umap[h] += 1;
        }
        return ans;
    }
private :
    const int eraser = 0x3ffff;
    unordered_map<char, int> ati{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    int hash(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
            ans = ((ans & eraser) << 2) + ati[s[i]];
        return ans;
    }
};
