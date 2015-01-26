/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() == 0)
            return 0;
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            map<double, int> map;
            int same = 0, straight = 0;
            for (int k = 0; k < points.size(); k++) {
                if (points[i].y == points[k].y && points[i].x == points[k].x) {
                    same++;
                    continue;
                }
                if (points[i].x == points[k].x) {
                    straight++;
                    continue;
                }
                double v = (points[i].y - points[k].y) * 1.0 / (points[i].x - points[k].x);
                map[v]++;
            }
            ans = max(ans, same);
            ans = max(ans, straight + same);
            for (auto it = map.begin(); it != map.end(); it++)
                ans = max(ans, it->second + same);
        }
        return ans;
    }
};
