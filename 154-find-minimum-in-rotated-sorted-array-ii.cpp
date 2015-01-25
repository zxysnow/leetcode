class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, r = num.size() - 1;
        while (l < r && num[l] >= num[r]) {
            int mid = (l + r) >> 1;
            if (num[mid] > num[l])
                l = mid + 1;
            else if (num[mid] < num[l])
                r = mid;
            else
                l++;
        }
        return num[l];
    }
};
