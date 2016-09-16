class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode():nodes(26,nullptr),isEnd(false) {
    }
    vector<TrieNode*> nodes;
    bool isEnd;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for(int i=0;i<word.size();++i){
            int index = word[i]-'a';
            if(p->nodes[index]==nullptr){
                p->nodes[index] = new TrieNode();
            }
            p = p->nodes[index];
        }
        p->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        for(int i=0;i<word.size();++i){
            int index = word[i]-'a';
            if(p->nodes[index]==nullptr){
                return false;
            }
            p = p->nodes[index];
        }
        return p->isEnd == true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for(int i=0;i<prefix.size();++i){
            int index = prefix[i]-'a';
            if(p->nodes[index]==nullptr){
                return false;
            }
            p = p->nodes[index];
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