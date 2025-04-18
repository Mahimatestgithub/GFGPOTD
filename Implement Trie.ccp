// User function template for C++
class TrieNode {
public:
    TrieNode* children[26]; // assuming only lowercase letters
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for(int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string &word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool search(string &word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
                return false;
            node = node->children[index];
        }
        return node->isEndOfWord;
    }

    bool isPrefix(string &word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
                return false;
            node = node->children[index];
        }
        return true;
    }
};
