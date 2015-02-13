class Solution {
public:
    int find_lower(int a[], int n, int target) {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (target <= a[mid])
                r = mid;
            else
                l = mid + 1;
        }
        if (a[l] != target)
            return -1;
        return l;
    }
    int find_upper(int a[], int n, int target) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (target >= a[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l - 1;
    }
    vector<int> searchRange(int A[], int n, int target) {
        int a = find_lower(A, n, target);
        if (a == -1)
            return vector<int>{-1, -1};
        int b = find_upper(A, n, target);
        return vector<int>{a, b};        
    }
};
