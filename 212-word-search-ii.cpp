class TrieNode {
public:
    // Initialize your data structure here.
    vector<TrieNode*> child;
    bool end;
    TrieNode() : child(26, NULL), end(false) {
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *head = root;
        for (int i = 0; i < s.size(); i++) {
            if (head->child[s[i] - 'a'] == NULL) {
                head->child[s[i] - 'a'] = new TrieNode();
            }
            head = head->child[s[i] - 'a'];   
        }
        head->end = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *head = root;
        for (int i = 0; i < key.size(); i++) {
            if (head->child[key[i] - 'a'] == NULL) {
                return false;
            }
            head = head->child[key[i] - 'a'];
        }
        if (head->end) {
            head->end = false;
            return true;
        }
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *head = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (head->child[prefix[i] - 'a'] == NULL) {
                return false;
            }
            head = head->child[prefix[i] - 'a'];
        }
        return true;   
    }

private:
    TrieNode* root;
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        Trie trie;
        for (auto &str : words)
            trie.insert(str);
        int n = board.size();
        if (n == 0)
            return ans;
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        string str;
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                str.push_back(board[i][k]);
                dfs(i, k, trie, str, ans, board, visited);
                str.pop_back();
            }
        }
        return ans;
    }

private :
    int dir[8] = {0, 1, 0, -1, -1, 0, 1, 0};
    void dfs(int x, int y, Trie &trie, string &str, vector<string> &ans, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        if (!trie.startsWith(str))
            return ;
        if (trie.search(str))
            ans.push_back(str);
        visited[x][y] = true;
        for (int i = 0; i < 8; i += 2) {
            int xx = x + dir[i];
            int yy = y + dir[i + 1];
            if (xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size() && !visited[xx][yy]) {
                str.push_back(board[xx][yy]);
                dfs(xx, yy, trie, str, ans, board, visited);
                str.pop_back();
            }
        }
        visited[x][y] = false;
    }
};

