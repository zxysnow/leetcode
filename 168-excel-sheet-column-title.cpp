class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n) {
            ans = char('A' + (n - 1) % 26) + ans;
            n = (n - 1) / 26;
        }
        return ans;
    }
};
