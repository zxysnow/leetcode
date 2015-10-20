class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, r = num.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (num[mid] > num[r])
                l = mid + 1;
            else if (num[mid] < num[r])
                r = mid;
            else
                r--;
        }
        return num[l];
    }
};
