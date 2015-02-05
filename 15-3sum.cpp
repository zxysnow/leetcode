class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int n = num.size();
        sort(num.begin(), num.end());
        vector<vector<int> > ans;
        for (int i = 0; i < n - 1; i++) {
            if (i != 0) {
                while(i < n && num[i] == num[i - 1])
                    i++;
            }
            int k = i + 1,  p = n - 1;
            while (k < p) {
                if (num[k] + num[p] == -num[i]) {
                    ans.push_back({num[i], num[k], num[p]});
                    while (k + 1 < p && num[k + 1] == num[k])
                        k++;
                    int t = num[p];
                    while (t == num[p] && k < p)
                        p--;
                    continue;
                }
                if (num[k] + num[p] > -num[i]) {
                    p--;
                } else {
                    k++;
                }
            }
        }
        return ans;
    }
};
