class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, r = num.size() - 1;
        while (l < r) {
            if (num[l] < num[r])
                return num[l];
            int mid = (l + r) >> 1;
            if (num[mid] >= num[l])
                l = mid + 1;
            else
                r = mid;
        }
        return num[l];
    }
};
