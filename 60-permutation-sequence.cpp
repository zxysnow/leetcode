class Solution {
public:
     string getPermutation(int n, int k) {
        string ans = "";
        vector<int> f(n, 1);
        vector<int> id(n + 1, 0);
        for (int i = 0; i < n; i++)
            id[i] = i + 1;
        for (int i = 2; i < n; i++)
            f[i] = f[i - 1] * i;
		k--;
        for (int i = n - 1; i >= 0; i--) {
            ans += char('0' + id[k / f[i]]);
            id.erase(id.begin() + k / f[i]);
            k %= f[i];
        }
        return ans;
    }
};
