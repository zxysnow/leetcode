class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir;
        int pos = 0;
        while (pos < path.size()) {
            int t = path.find("/", pos + 1);
            if (t == -1) {
                t = path.size();
            }
            string str = path.substr(pos + 1, t - pos - 1);
            pos = t;
            if (str == "" || str == ".")
                continue;
            if (str == "..") {
                if (!dir.empty())
                    dir.pop_back();
                continue;
            }
            dir.push_back(str);
        }
        if (dir.empty())
            return "/";
        string rst = "";
        for (int i = 0; i < dir.size(); i++)
            rst += "/" + dir[i];
        return rst;
    }
};
