class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);
        
        int pos = 0;
        while (pos < v1.size() && pos < v2.size()) {
            if (v1[pos] > v2[pos])
                return 1;
            if (v1[pos] < v2[pos])
                return -1;
            ++pos;
        }
        
        if (pos < v1.size()) {
            if (allZero(v1, pos))
                return 0;
            return 1;
        }
        if (pos < v2.size()) {
            if (allZero(v2, pos))
                return 0;
            return -1;
        }
        return 0;
    }

private :
    vector<int> split(string v) {
        vector<int> ans;
        stringstream ss(v);
        string item;
        while(getline(ss, item, '.')) {
            ans.push_back(atoi(item.c_str()));
        }
        return ans;
    }

    bool allZero(vector<int> v, int x) {
        for (int i = x; i < v.size(); i++)
            if (v[i] != 0)
                return false;
        return true;
    }
};
