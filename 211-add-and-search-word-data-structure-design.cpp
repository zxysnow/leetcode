class TrieNode {
public:
    vector<TrieNode*> child;
    int max_len;	//剪枝
    bool end;
    TrieNode() : child(26, NULL), end(false), max_len(0) {
    }
};

class WordDictionary {
public:
    
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *head = root;
        for (int i = 0; i < word.size(); i++) {
            head->max_len = max(head->max_len, int(word.size() - i));
            int id = word[i] - 'a';
            if (head->child[id] == NULL) {
                head->child[id] = new TrieNode();
            }
            head = head->child[id];
        }
        head->end = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return dfs(root, word, 0);
    }
    
    bool dfs(TrieNode *root, string &word, int x) {
        if (root == NULL)
            return false;
        if (x == word.size())
            return root->end;
        if (root->max_len < word.size() - x)
            return false;
        if (word[x] != '.')
            return dfs(root->child[word[x] - 'a'], word, x + 1);
        for (int i = 0; i < root->child.size(); i++) {
            if (dfs(root->child[i], word, x + 1))
                return true;
        }
        return false;
    }
    
    private:
        TrieNode *root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
