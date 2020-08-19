// For StreamChecker c-tor
// Time O(N*M), where N is a number of input words, and M is the word length
// Space O(N*M)
// For each query()
// Time O(M)
// Space O(M) - One could limit the size of deque to be equal to the length of the longest input word.
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool word = false;
    
    ~TrieNode() {
        for(auto i : children) {
            delete i.second;
        }
    }
};

class StreamChecker {
private:
    TrieNode* root = new TrieNode();
    deque<char> stream;
    
public:
    StreamChecker(vector<string>& words) {
        for (auto word : words) {
            TrieNode* node = root;
            reverse(word.begin(), word.end()); 
            for (auto ch : word) {
                if (!node->children.count(ch)) {
                    node->children[ch] = new TrieNode();
                }
                node = node->children[ch];
            }
            node->word = true;    
        }
    }
    
    bool query(char letter) {
        stream.push_front(letter);
    
        TrieNode* node = root;
        for (auto ch : stream) {
            if (node->word) {
                return true;    
            }
            if (!node->children.count(ch)) {
                return false;    
            }
            node = node->children[ch];    
        }
        return node->word;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
