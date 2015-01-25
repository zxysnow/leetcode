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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int start = newInterval.start, end = newInterval.end;
        vector<Interval> ans;
        int i;
        for (i = 0; i < intervals.size(); i++) {
            if (intervals[i].end < start)
                ans.push_back(intervals[i]);
            if (intervals[i].start > end)
                break;
            if (intervals[i].start >= start && intervals[i].start <= end || intervals[i].end <= end && intervals[i].end >= start
                || start >= intervals[i].start && start <= intervals[i].end) {
                start = min(start, intervals[i].start);
                end = max(end, intervals[i].end);
            }
        }
        ans.push_back(Interval(start, end));
        for (; i < intervals.size(); i++)
            ans.push_back(intervals[i]);
        return ans;
    }
};
