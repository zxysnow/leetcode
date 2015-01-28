class Solution {
public:
    int findK(int a[], int na, int b[], int nb, int k) {
		if (na == 0)
			return b[k - 1];
		if (nb == 0)
			return a[k - 1];
		if (k == 1)
			return min(a[0], b[0]);
        int k1, k2;
        if (na < nb) {
            k1 = min(na, k / 2);
            k2 = k - k1;
        } else { 
            k2 = min(nb, k / 2);
            k1 = k - k2;
        }
        if (a[k1 - 1] < b[k2 - 1]) {
            return findK(a + k1, na - k1, b, k2, k - k1);     
        } else if (a[k1 - 1] > b[k2 - 1]){
            return findK(a, k1, b + k2, nb - k2, k - k2);
        } else {
			return a[k1 - 1];
		}
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) % 2 == 1) {
            int k = (m + n + 1) / 2;
            return findK(A, m, B, n, k);
        } else {
            int k = (m + n) / 2;
            return (findK(A, m, B, n, k) + findK(A, m, B, n, k + 1)) / 2.0;
        }
    }
};
