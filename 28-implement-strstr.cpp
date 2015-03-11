class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if (needle[0] == '\0')
            return 0;
        vector<int> next = getNext(needle);
        int k = -1;
        for (int i = 0; haystack[i] != '\0'; i++) {
            while (k >= 0 && needle[k + 1] != haystack[i])
                k = next[k];
            if (needle[k + 1] == haystack[i]) {
                k++;
                if (needle[k + 1] == '\0')
                    return i - k;
            }
        }
        return -1;
    }
private :
    vector<int> getNext(char *p) {
        vector<int> next;
        next.push_back(-1);
        int k = -1;
        for (int i = 1; p[i] != '\0'; i++) {
            while (k >= 0 && p[k + 1] != p[i])
                k = next[k];
            if (p[k + 1] == p[i])
                k++;
            next.push_back(k);
        }
        return next;
    }
};
