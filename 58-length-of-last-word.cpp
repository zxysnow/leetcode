class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if( *s == '\0' )
            return 0;
        int ans = (*s++ == ' ' ? 0 : 1);
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
