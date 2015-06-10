class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C - A) * (D - B) + (G - E) * (H - F);
        if (B >= H || F >= D || A >= G || E >= D)
            return area;
        int top = min(D, H);
        int bottom = max(B, F);
        int left = max(A, E);
        int right = min(C, G);
        return area - (top - bottom) * (right - left);
    }
};
