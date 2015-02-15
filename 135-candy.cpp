class Solution {
public:
    int candy(vector<int> &ratings) {
        int sum = 1, pos = 0, num = 1;
        int n = ratings.size();
        if (n == 0)
            return 0;
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                num++;
                sum += num;
            } else if (ratings[i] == ratings[i - 1]) {
                num = 1;
                sum += num;
            } else {
                int t = 0;
                while (i < n && ratings[i] < ratings[i - 1]) {
                    sum += ++t;
                    i++;
                }
                if (num <= t)
                    sum += (t + 1 - num);
                num = 1;
                i--;
            }
        }
        return sum;
    }
};
