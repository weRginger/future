class AutocompleteSystem {
public:
    class Word {
    public:
        int freq;
        string w;
        Word(string w_, int freq_): w(w_), freq(freq_) {}
    };
    class TrieNode {
    public:
        vector<Word*> s;
        unordered_map<char, TrieNode*> children;
        TrieNode() {}
    };
    unordered_map<string, Word*> words;
    
    void add(string sentence, int times) {
        if (!words.count(sentence)) {
            words[sentence] = new Word(sentence, times);
            auto w = words[sentence];
            auto cur = root;
            for (const auto c : sentence) {
                if (cur->children[c] == nullptr) cur->children[c] = new TrieNode();
                cur = cur->children[c];
                cur->s.push_back(w);
            }
        } else ++words[sentence]->freq;
    }
    
    TrieNode *root, *cur;
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        for (int i = 0; i < sentences.size(); ++i) add(sentences[i], times[i]);
        cur = root;
    }
    
    string ss;
    vector<string> input(char c) {
        vector<string> res;
        if (c == '#') {
            add(ss, 1);
            ss.clear();
            cur = root;
            return res;
        }
        ss += c;
        if (cur == nullptr) return res;
        cur = cur->children[c];
        if (cur == nullptr) return res;
        const auto cmp = [](const Word *a, const Word *b) {
            if (a->freq != b->freq) return a->freq > b->freq;
            return a->w < b->w;
        };
        priority_queue<Word*, vector<Word*>, decltype(cmp)> pq(cmp);
        for (auto t : cur->s) {
            pq.push(t);
            if (pq.size() > 3) pq.pop();
        }
        while (!pq.empty()) {
            res.push_back(pq.top()->w);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
