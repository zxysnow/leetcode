class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        for (int i : nums) {
            if (uset.count(i))
                return true;
            uset.insert(i);
        }
        return false;
    }
};
