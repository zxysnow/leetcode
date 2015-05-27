class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> now;
        vector<string> ans;
        int len = 0;
        for (int i = 0; i <= words.size(); i++) {
            if (i == words.size() || len + now.size() + words[i].size() > maxWidth) {
                string s;
                if (now.size() == 1 || i == words.size()) {
                    for (int k = 0; k < now.size(); k++) {
                        s += now[k];
                        if (k != now.size() - 1)
                            s += ' ';
                    }
                    s += space(maxWidth - (len + now.size() - 1));
                } else {
                    int base = (maxWidth - len) / (now.size() - 1);
                    int lastSpace = (maxWidth - len) % (now.size() - 1);
                    for (int k = 0; k < now.size(); k++) {
                        s += now[k];
                        if (k != now.size() - 1) {
                            s += space(base + (lastSpace > 0 ? 1 : 0));
                                lastSpace--;
                        }
                    }
                }
                ans.push_back(s);
                if (i == words.size())
                	break;
                len = words[i].size();
                now.clear();
                now.push_back(words[i]);
            } else {
                now.push_back(words[i]);
                len += words[i].size();
            }
        }
        return ans;
    }

private :
    string space(int x) {
        string s;
        for (int i = 0; i < x; i++)
            s += ' ';
        return s;
    }
};
