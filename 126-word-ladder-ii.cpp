class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> ans;
        if(start == end)
            return ans;
        dict.insert(start);
        dict.insert(end);
        int n = dict.size();
        vector<int> stoe(n, INT_MAX);
        vector<int> etos(n, INT_MAX);
        vector<string> vd;
        unordered_map<string, int> umap;
        int cnt = 0;
        for (auto &i : dict) {
            vd.push_back(i);
            umap[i] = cnt++;
        }
        int min_len = SPFA(start, end, umap, stoe);
        if (min_len == INT_MAX)
            return ans;
        SPFA(end, start, umap, etos);
        vector<unordered_set<string> > vset(min_len + 1);

        for (int i = 0; i < n; i++) {
            if (stoe[i] != INT_MAX && etos[i] != INT_MAX && stoe[i] + etos[i] == min_len) {
                vset[stoe[i]].insert(vd[i]);
            }
        }
        ans.push_back(vector<string>{start});
        vector<vector<string>> next;

        for (int i = 1; i <= min_len; i++) {
            next.clear();
            for (int k = 0; k < ans.size(); k++) {
                string node = ans[k].back();
                vector<string> t = ans[k];
                for (int c = 0; c < node.size(); c++) {
                    char ch = node[c];
                    for (int j = 0; j < 26; j++) {
                        if (ch != 'a' + j) {
                            node[c] = 'a' + j;
                            if (vset[i].count(node)) {
                                t.push_back(node);
                                next.push_back(t);
                                t.pop_back();
                            }
                        }
                    }
                    node[c] = ch;
                }
            }
            ans = next;
        }
        return ans;
    }

private:
    int SPFA(string start, string end, unordered_map<string, int> dict, vector<int>& dist) {
        int n = dict.size();
        if (start == end)
            return 0;
        queue<string> q;
        unordered_set<string> used;

        used.insert(start);
        dist[dict[start]] = 0;
        q.push(start);

        int min_len = INT_MAX;
        while (!q.empty()) {
            string now = q.front();
            q.pop();
            used.erase(now);
            int x = dict[now];
            for (int i = 0; i < now.size(); i++) {
                for (int k = 0; k < 26; k++) {
                    string t = now;
                    if (t[i] == 'a' + k)
                        continue;
                    t[i] = 'a' + k;
                    if (dict.count(t)) {
                        int to = dict[t];
                        if (dist[to] > dist[x] + 1) {
                            dist[to] = dist[x] + 1;
                            if (used.count(t) == 0) {
                                q.push(t);
                                used.insert(t);
                            }
                        }
                    }
                }
            }
        }
        return dist[dict[end]];
    }
};
