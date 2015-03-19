class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0, total = 0, start = 0;
        for(int i = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
};
