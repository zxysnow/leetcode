class Solution {
public:
    string minWindow(string S, string T) {
        const int MAX = 260;
        queue<int> q;
        vector<int> pos(MAX, 0);
        vector<int> cnt(MAX, 0);
        int len = INT_MAX, p = -1;
        int c = 0;
        for (int i = 0; i < T.size(); i++)
            cnt[T[i]]++;
        vector<int> red = cnt;
        for (int i = 0; i < S.size(); i++) {
            int id = S[i];
            if (cnt[id] == 0)
                continue;
            pos[id] = i;
            red[id]--;
            if (red[id] >= 0)
                c++;
            q.push(i);
            while (!q.empty() && pos[S[q.front()]] > q.front() && red[S[q.front()]] < 0) {
                int k = S[q.front()];
                red[k]++;
                if (red[k] > 0)
                    c--;
                q.pop();
            }
            if (c == T.size() && len > i - q.front()) {
                len = i - q.front();
                p = q.front();
            }
        }
        return len == INT_MAX ? "" : S.substr(p, len + 1);
    }
};
