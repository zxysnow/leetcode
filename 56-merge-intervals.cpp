/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    class cmp {
    public:
        bool operator()(Interval a, Interval b) {
            return a.start < b.start;
        }
    };
    vector<Interval> merge(vector<Interval> &intervals) {
        int n = intervals.size();
        vector<Interval> ans;
        if (n == 0)
            return ans;
        sort(intervals.begin(), intervals.end(), cmp());
        ans.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            if (intervals[i].start > ans.back().end) {
                ans.push_back(intervals[i]);
            } else {
                ans.back().end = max(ans.back().end, intervals[i].end);
            }
        }
        return ans;
    }
};
