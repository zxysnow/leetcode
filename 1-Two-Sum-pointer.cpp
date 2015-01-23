class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        vector<pair<int, int> > p;
        int l = 0, r = numbers.size() - 1, n = numbers.size();
        for (int i = 0; i < n; i++)
            p.push_back(make_pair(numbers[i], i + 1));
        sort(p.begin(), p.end());
        while (l < r) {
            if (p[l].first + p[r].first == target) {
                ans.push_back(p[l].second);
                ans.push_back(p[r].second);
                if (ans[0] > ans[1])
                    swap(ans[0], ans[1]);
                return ans;
            } 
            if (p[l].first + p[r].first < target)
                l++;
            else
                r--;
        }
    }
};
