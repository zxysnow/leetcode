class line {
public :
    line(int x, int y, int op) : x(x), y(y), op(op) {}
    line() {}
    int x, y;
    int op;
};
bool cmp(const line &a, const line &b) {
	if (a.x == b.x && a.op == b.op && a.op == 1)
		return a.y > b.y;
	if (a.x == b.x && a.op == b.op && a.op == -1)
		return a.y < b.y;
	if (a.x == b.x)
		return a.op > b.op;
    return a.x < b.x;
}
class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        vector<pair<int, int> > ans;
        map<int, int, greater<int> > mp;
        vector<line> lv;
        line t;
        for (int i = 0; i < buildings.size(); i++) {
            line t(buildings[i][0], buildings[i][2], 1);
            lv.push_back(t);
            t.op = -1;
            t.x = buildings[i][1];
            lv.push_back(t);
        }
        sort(lv.begin(), lv.end(), cmp);
        for (line &t : lv) {
            if (t.op == 1) {
                int cnt = ++mp[t.y];
                if (cnt == 1 && mp.begin()->first == t.y) {
                    ans.push_back(make_pair(t.x, t.y));
                }
            } else {
                int cnt = --mp[t.y];
                if (cnt == 0 && t.y == mp.begin()->first) {
                    mp.erase(t.y);
                    if (mp.empty()) {
                        ans.push_back(make_pair(t.x, 0));
                    } else {
                        ans.push_back(make_pair(t.x, mp.begin()->first));
                    }
                    continue;
                }
                if (cnt == 0)
                    mp.erase(t.y);
            }
        }
        return ans;
    }
};
