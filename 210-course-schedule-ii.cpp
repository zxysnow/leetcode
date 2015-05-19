class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > list(numCourses);
        vector<int> in_degree(numCourses, 0);
        vector<int> order;
        for (int i = 0; i < prerequisites.size(); i++) {
            list[prerequisites[i].second].push_back(prerequisites[i].first);
            in_degree[prerequisites[i].first]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0)
                q.push(i);
        }
        int cnt = q.size();
        while (!q.empty()) {
            int x = q.front();
            order.push_back(x);
            q.pop();
            for (int i = 0; i < list[x].size(); i++) {
                if (--in_degree[list[x][i]] == 0) {
                    q.push(list[x][i]);
                    cnt++;
                }
            }
        }
        return cnt == numCourses ? order : vector<int>();
    }
};
