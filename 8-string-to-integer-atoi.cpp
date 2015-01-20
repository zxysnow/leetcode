class Solution {
public:
    int atoi(const char *str) {
        int flag = 1;
        long long ans = 0;
        while (*str == ' ')
            str++;
        flag = 1;
        if (*str == '-' || *str == '+') {
            if (*str == '-')
                flag = -1;
            str++;
        }
        while (*str >= '0' && *str <= '9') {
            ans *= 10;
            ans += *str - '0';
            str++;
            if (ans * flag >= INT_MAX) {
                return INT_MAX;
            }
            if (ans * flag <= INT_MIN) {
                return INT_MIN;
            } 
        }
        return ans * flag;
    }
};
