class Solution {
public:
    string convert(string s, int nRows) {
        int length = s.size();
        if (length == 0 || nRows == 1)
            return s;
        string ans = "";
        int step = nRows * 2 - 2;
        int b = 2;
        for (int i=0; i<length; i+=step)
            ans += s[i];
        for (int i=1; i<nRows-1; i++) {
            int st = b;
            for (int k=i; k<length; k+=st) {
                ans += s[k];
                st = (st == b ? step - b : b);
            }
            b += 2;
        }
        for (int i=nRows-1; i<length; i+=step) {
            ans += s[i];
	}
	return ans;
    }
};
