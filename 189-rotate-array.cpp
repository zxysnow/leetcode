class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        swapArray(nums, n - k);
        swapArray(nums + n - k, k);
        swapArray(nums, n);
    }

private :
    void swapArray(int* num, int n) {
        for (int i = 0; i < n / 2; i++)
            swap(num[i], num[n - i - 1]);
    }
};
