class Solution {
public:
    int removeDuplicates(int A[], int n) {
        return unique(A, A+n) - A;
    }
};
