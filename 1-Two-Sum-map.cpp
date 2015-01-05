class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        map<int, int> m;
        for(int i=0; i<numbers.size(); i++)
            m[numbers[i]] = i;
        for(int i=0; i<numbers.size(); i++) {
            int other = target - numbers[i];
            map<int, int>::iterator it = m.find(other);
            if( it != m.end() && it->second != i ) {
                ans.push_back(i + 1);
                ans.push_back(it->second + 1);
                return ans;
            }
        }
    }
};
