class Solution {
public:
    bool canJump(int A[], int n) {
        int far = 0;
        for (int i = 0; i < n; i++) {
            if (far < i)
                break;
            far = max(A[i] + i, far);
        }
        return far >= n - 1;
    }
};
