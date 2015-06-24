class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        unordered_map<string, pair<int, int> > umap;
        vector<bool> visit(s.size(), false);
        vector<int> ans;
        int id = 0;
        for (int i = 0; i < words.size(); i++) {
            if (umap.count(words[i])) {
                umap[words[i]].second++;
            } else {
                umap[words[i]] = make_pair(id++, 1);
            }
        }
        int one_len = words[0].size();
        int all_len = one_len * words.size();
        for (int i = 0; i <= (int)s.size() - all_len; i++) {
			if (visit[i])
			    continue;
			int pos = i, sum = 0;
			vector<int> cnt(umap.size(), 0);
			while(1) {
		        while (pos + (n - sum) * one_len <= s.size() && check(s.substr(pos, one_len), cnt, umap)) {
		            pos += one_len;
		            sum++;
		        }
		        visit[pos - sum * one_len] = true;
		        if (sum == n)
				    ans.push_back(pos - all_len);
				if (sum <= 1)
				    break;
	            cnt[umap[s.substr(pos - sum * one_len, one_len)].first]--;
				sum--; 
			}
		}
        return ans;
    }
private :
    bool check(string sub, vector<int> &cnt, unordered_map<string, pair<int, int> >& umap) {
        if (umap.count(sub)) {
            if (umap[sub].second > cnt[umap[sub].first]) {
                cnt[umap[sub].first]++;
                return true;
            }
        }
        return false;
    }
};
