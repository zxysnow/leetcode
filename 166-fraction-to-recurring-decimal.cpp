class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        string flag = "-";
        if (((numerator < 0) ^ (denominator < 0)) == 0)
            flag = "";
        long long num = abs(numerator * 1ll);
        long long den = abs(denominator * 1ll);
        long long integer = num / den;
        num %= den;
        if (num == 0)
            return flag + to_string(integer);
        return flag + to_string(integer) + "." + decimal(num, den);
    }

private :
    string decimal(long long n, long long d) {
        unordered_map<long long, int> umap;
        string dec;
        umap[n] = 0;
        while (n != 0) {
            n *= 10;
            dec += to_string(n / d);
            n %= d;
            if (!umap.count(n)) {
                umap[n] = dec.size();
            } else {
                int pos = umap[n];
                return dec.substr(0, pos) + "(" + dec.substr(pos) + ")";
            }
        }
        return dec;
    }
};
