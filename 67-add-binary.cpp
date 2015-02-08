class Solution {
public:
    string tail(string b, int n, int &flag) {
        string sum = "";
        while ((int)b.size() - n - 1 >= 0) {
            int s = b[(int)b.size() - n - 1] - '0' + flag;
            flag = s / 2;
            s %= 2;
            sum += (s + '0');
            n++;
        }
        return sum;
    }
    string addBinary(string a, string b) {
        string sum = "";
        int n = min(a.size(), b.size());
        int an = a.size(), bn = b.size();
        int flag = 0;
        for (int i = 0; i < n; i++) {
            int s = a[an - i - 1] - '0' + b[bn - i - 1] - '0' + flag;
            flag = s / 2;
            s = s % 2;
            sum += (s + '0');
        }
        sum += tail(a, n, flag);
        sum += tail(b, n, flag);
        if (flag)
            sum += '1';
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
