class Solution {
public:
    int majorityElement(vector<int> &num) {
        int now = num[0], cnt = 1, len = num.size();
        for (int i = 1; i < len; i++) {
            if (num[i] == now) {
                cnt++;
            } else {
                cnt--;
                if (cnt <= 0) {
                    cnt = 1;
                    now = num[i];
                }
            }
        }
        return now;
    }
};
