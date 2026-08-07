class TrieNode {
public:
    vector<TrieNode*> children;
    bool isWord;

    TrieNode() {
        isWord = false;
        children = vector<TrieNode*>(26, nullptr);
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(TrieNode* node, string& word, int index) {
        while (index < word.size() && word[index] != '.') {
            int i = word[index] - 'a';
            if (!node->children[i])
                return false;
            index++;
            node = node->children[i];
        }
        if (index == word.size())
            return node->isWord;
        for (auto child: node->children) {
            if (child && dfs(child, word, index + 1))
                return true;
        }
        return false;
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;

        for (auto c: word) {
            int i = c - 'a';
            if (!node->children[i]) {
                node->children[i] = new TrieNode();
            }
            node = node->children[i];
        }

        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        return dfs(node, word, 0);
    }
};
