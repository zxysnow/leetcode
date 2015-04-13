/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
            return NULL;
        unordered_map<int, UndirectedGraphNode*> mp;
        dfs(node, mp);
        return mp[node->label];
    }

private :
    void dfs(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*> &mp) {
        int label = node->label;
        UndirectedGraphNode *now = mp.count(label) == 0 ? new UndirectedGraphNode(label) : mp[label];
        mp[label] = now;
        for (int i = 0; i < node->neighbors.size(); i++) {
            int to_label = node->neighbors[i]->label;
            UndirectedGraphNode* to =  mp.count(to_label) == 0 ? new UndirectedGraphNode(to_label) : mp[to_label];
            now->neighbors.push_back(to);
            if (mp.count(to_label)) {
                mp[to_label] = to;
                continue;
            }
            mp[to_label] = to;
            dfs(node->neighbors[i], mp);
        }
    }
};
