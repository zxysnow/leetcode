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
        return head->end;
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

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
