class Solution {
public:
    string addBinary(string a, string b) {
        ostringstream oss;
        int  i = a.size() - 1, k = b.size() - 1;
        int carry = 0;
        while (i >= 0 || k >= 0) {
            int num = carry;
            if (i >= 0)
                num += a[i--] - '0';
            if (k >= 0)
                num += b[k--] - '0';
            carry = num / 2;
            num %= 2;
            oss << char(num + '0');
        }
        if (carry)
            oss << '1';
        string ans = oss.str();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};