class Solution {
public:
    int bsearch_find_pivot(int a[], int n) {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (a[mid] < a[0]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    int search(int A[], int n, int target) {
        int pivot = bsearch_find_pivot(A, n);
    	int s = pivot, t = pivot;
    	if (target <= A[n-1])
    	    t = n;
        if (target >= A[0])
            s = 0;
        int pos = lower_bound(A + s, A + t, target) - A;
        if (pos < n && A[pos] == target)
            return pos;
        return -1;
    }
};
