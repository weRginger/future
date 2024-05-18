// use Trie with unordered_map
class TrieNode {
public:
    bool isKey;
    unordered_map<char, TrieNode*> children;
    TrieNode(): isKey(false) {}
};

class WordDictionary {
private:
    TrieNode* root;

    bool query(string word, TrieNode* node) {
        for(int i = 0; i < word.size(); i++) {
            if(!(node->children).count(word[i])) {
                if(word[i] == '.') {
                    for(pair<char, TrieNode*> item : node->children) {
                        if(query(word.substr(i+1), item.second))
                            return true;
                    }
                }
                // NOTE: cannot put "else" here, since we want to return false if 
                // no true case happens in "if(word[i] == '.')"
                return false;
            } else {
                node = (node->children)[word[i]];
            }
        }
        return node->isKey;
    }

    void clear(TrieNode* root) {
        if(!root) return;
        for(pair<char, TrieNode*> item : root->children) {
            clear(item.second);
        }
        delete root;
    }
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    ~WordDictionary() {
        clear(root);
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* run = root;
        for (char c : word) {
            if (!run->children.count(c))
                run->children[c] = new TrieNode();
            run = run->children[c];
        }
        run->isKey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return query(word, root);
    }
};

// use unordered_map<int, unordered_set>
class WordDictionary {
private:
    unordered_map<int, unordered_set<string>> d;
    
public:
    WordDictionary() {}

    // Adds a word into the data structure.
    void addWord(string word) {
        int m = word.size();
        d[m].insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        int m = word.size();
        if (d.count(m)) {
            for(auto w : d[m]) {
                int i = 0;
                while ((i < m) && (w[i] == word[i] || word[i] == '.')) {
                    i++;
                }
                if (i == m) return true;    
            }    
        }
        return false;
    }
};

// use trie with array
class TrieNode {
public:
    bool isKey;
    TrieNode* children[26];
    TrieNode(): isKey(false) {
        memset(children, NULL, sizeof(TrieNode*) * 26);
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    ~WordDictionary() {
        clear(root);
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* run = root;
        for (char c : word) {
            if (!(run -> children[c - 'a']))
                run -> children[c - 'a'] = new TrieNode();
            run = run -> children[c - 'a'];
        }
        run -> isKey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return query(word.c_str(), root);
    }

private:
    TrieNode* root;

    bool query(const char* word, TrieNode* node) {
        TrieNode* run = node;
        for (int i = 0; word[i]; i++) {
            if (run && word[i] != '.')
                run = run -> children[word[i] - 'a'];
            else if (run && word[i] == '.') {
                TrieNode* tmp = run;
                for (int j = 0; j < 26; j++) {
                    run = tmp -> children[j];
                    if (query(word + i + 1, run))
                        return true;
                }
            }
            else break;
        }
        return run && run -> isKey;
    }

    void clear(TrieNode* root) {
        if(!root) return;
        for(int i = 0; i < 26; i++) {
            if(root -> children[i]) {
                clear(root -> children[i]);
            }
        }
        delete root;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
