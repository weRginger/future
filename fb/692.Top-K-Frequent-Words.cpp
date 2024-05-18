// Time O(N*logk)
// Space O(N)
class Solution {
private:
    typedef pair<string, int> Node;
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (const string& word : words)
            ++count[word];
        
        auto comp = [](const Node& a, const Node& b) {
            // order by alphabet ASC
            if (a.second == b.second) 
                return  a.first < b.first;
            // order by freq DESC
            return a.second > b.second;
        };
        
        // Min heap by frequency
        priority_queue<Node, vector<Node>, decltype(comp)> q(comp);
        
        // O(n*logk)
        for (const auto& kv : count) {
            q.push(kv);
            if (q.size() > k) q.pop();
        }
        
        vector<string> ans;
        
        while (!q.empty()) {
            ans.push_back(q.top().first);
            q.pop();
        }
        
        // the reason lies in how comp is defined
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
