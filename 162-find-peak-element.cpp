class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int l = 0, r = num.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mid + 1 < num.size() && num[mid + 1] > num[mid])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
