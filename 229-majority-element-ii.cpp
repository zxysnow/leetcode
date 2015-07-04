class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        vector<int> value(2, 0), cnt(2, 0);
        for (int &x : nums) {
            calculate(value, cnt, x);
        }
        if (isMajority(nums, value[0]))
            ans.push_back(value[0]);
        if (value[0] != value[1] && isMajority(nums, value[1]))
            ans.push_back(value[1]);
        return ans;
    }
private :
    bool isMajority(vector<int>& nums, int x) {
        int sum = 0;
        for (int &k : nums)
            sum += (k == x ? 1 : 0);
        return sum > nums.size() / 3;
    }
    void calculate(vector<int> &value, vector<int> &cnt, int x) {
        for (int i = 0; i < 2; i++) {
            if (cnt[i] != 0 && value[i] == x) {
                cnt[i]++;
                return ;
            }
        }
        for (int i = 0; i < 2; i++) {
            if (cnt[i] == 0) {
                value[i] = x;
                cnt[i] = 1;
                return ;
            }
        }
        for (int& c : cnt) {
            if (c > 0)
                c--;
        }
    }
};