class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        vector<int> ans(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int k = num2.size() - 1; k >= 0; k--) {
                int pos =  num1.size() - 1 - i + num2.size() - 1 - k;
                ans[pos] += (num1[i] - '0') * (num2[k] - '0');
                ans[pos + 1] += ans[pos] / 10;
                ans[pos] %= 10;
            }
        }
        int i = ans.size() - 1;
        while (ans[i] == 0)
            i--;
        ans.resize(i + 1);
        return vec2str(ans);
    }

private :
    string vec2str(vector<int> a) {
        string s;
        for (int i = a.size() - 1; i >= 0; i--) {
            s += char('0' + a[i]);
        }
        return s;
    }
};
