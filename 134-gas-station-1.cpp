class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int s = 0;
        for (int i = 0; i < gas.size(); i++)
            s += gas[i] - cost[i];
        if (s < 0)
            return -1;
        vector<int> g(gas.size(), 0);
        for (int i = 0; i < gas.size(); i++)
            g[i] = gas[i] - cost[i];
        for (int i = 0; i < gas.size(); i++)
            g[i + gas.size()] = g[i];
        int pos = 0, maxsum = -1, p = -1, sum = 0;
        for (int i = 0; i < g.size(); i++) {
            if (sum + g[i] < 0) {
                sum = 0;
                p = i;
                continue;
            }
            sum += g[i];
            if (sum > maxsum) {
                maxsum = sum;
                pos = p;
            }
        }
        if (maxsum < 0)
            return -1;
        return (pos + 1) % gas.size();
    }
};
