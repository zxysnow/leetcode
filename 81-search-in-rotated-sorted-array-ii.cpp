class Solution {
public:
    bool search(vector<int>& A, int target) {
		int l = 0, r = A.size() - 1;
		while (l <= r) {
			int mid = l + ((r - l) >> 2);
			if (A[mid] == target)
				return true;
			if (A[l] == A[mid]) {
				l++;
				continue;
			}
			if (A[l] < A[mid]) {
				if (A[l] <= target && target < A[mid])
					r = mid - 1;
				else
					l = mid + 1;
			} else {
				if (A[mid] < target && target <= A[r])
					l = mid + 1;
				else 
					r = mid - 1;
			}
		}
		return false;
	}
};
