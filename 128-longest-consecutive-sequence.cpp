class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> s;
        int ans = 0;
        for (int i = 0; i < num.size(); i++)
            s.insert(num[i]);
        for (int i = 0; i < num.size(); i++) {
            if (s.empty())
                break;
            if (s.count(num[i])) {
                int t = num[i] + 1, cnt = 1;
                s.erase(num[i]);
                while (s.count(t)) {
                    s.erase(t);
                    t++;
                    cnt++;
                }
                t = num[i] - 1;
                while (s.count(t)) {
                    s.erase(t);
                    t--;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
    
};
