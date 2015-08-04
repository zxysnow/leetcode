class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size() - 1;
        while (n >= 0 && s[n] == ' ')
            n--;
        int cnt = 0;
        while (n >= 0 && s[n] != ' ') {
            cnt++;
            n--;
        }
        return cnt;
    }
};