class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for(auto num : nums)
            freqs[num]++;
        
        auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        for(auto p : freqs) {
            if(pq.size() < k) {
                pq.push(p);
            } else {
                auto& min = pq.top();
                if(min.second < p.second) {
                    pq.pop();
                    pq.push(p);
                }
            }
        }
        
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        return ans;
    }
};
