class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for (int i : nums)
            s.push_back(to_string(i));
        sort(s.begin(), s.end(), compare);
        string ans;
        for(const string& str : s)
            ans += str;
        if (ans[0] == '0')
            return "0";
        return ans;
    }

private :
    static bool compare(const string& s1, const string& s2) {
        return s1 + s2 > s2 + s1;
    }
};
