class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int n = dict.size();
        if (start == end)
            return 0;
        queue<pair<string, int> > q;
        if (dict.count(start))
            dict.erase(start);
        q.push(make_pair(start, 1));
        while (!q.empty()) {
            pair<string, int> now = q.front();
            q.pop();
            for (int i = 0; i < now.first.size(); i++) {
                for (int k = 0; k < 26; k++) {
                    char t = now.first[i];
                    if (now.first[i] == 'a' + k)
                        continue;
                    now.first[i] = 'a' + k;
                    if (now.first == end)
                        return now.second + 1;
                    if (dict.count(now.first)) {
                        q.push(make_pair(now.first, now.second + 1));
                        dict.erase(now.first);
                    }
                    now.first[i] = t;
                }
            }
        }
        return 0;
    }
};
