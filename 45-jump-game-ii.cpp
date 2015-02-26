class Solution {
public:
    int jump(int A[], int n) {
        int far = 0;
        int now = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i > far) {
                far = now;
                ans++;
            }
            now = max(now, i + A[i]);
        }
        return ans;
    }
};
