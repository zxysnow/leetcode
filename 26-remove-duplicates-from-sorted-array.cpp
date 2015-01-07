class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int a = 1, b = 0;
        if( n == 0 )
            return 0;
        while( a < n ) {
            if( A[a++] != A[b] )
                A[++b] = A[a-1];
        }
        return b + 1;
    }
};
