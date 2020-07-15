// quickselect
// Time O(n) on average
// Space O(n)
// See LC for details

// min-heap
// Time O(n*logk)
// Space O(n)
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

// Butcket sort
// Time O(n)
// Space O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int max_freq = 1;
        for (const int num : nums)
            max_freq = max(max_freq, ++count[num]);
        unordered_map<int, vector<int>> buckets;
        for (const auto& kv : count)
            buckets[kv.second].push_back(kv.first);
        vector<int> ans;
        for (int i = max_freq; i >= 1; --i) {
            auto it = buckets.find(i);
            if (it == buckets.end()) continue;
            for(auto i : it->second) {
                ans.push_back(i);
                if(ans.size() == k) 
                    return ans;
            }
        }
        return ans;
    }
};
