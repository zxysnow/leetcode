class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int ans = 0;
        while (*s != '\0') {
            if (*s != ' ' && *(s-1) == ' ') 
                ans = 0;
            if (*s != ' ')
                ans++;
            s++;
        }
        return ans;
    }
};
