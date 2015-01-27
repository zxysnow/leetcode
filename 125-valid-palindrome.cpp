class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, k = s.size() - 1;
        while (i < k) {
            while (!(isalpha(s[i]) || isdigit(s[i])))
                i++;
            while (!(isalpha(s[k]) || isdigit(s[k])))
                k--;
            if (i > k)
                break;
            if (tolower(s[i]) == tolower(s[k])) {
                i++;
                k--;
                continue;
            }
            return false;
        }
        return true;
    }
};
