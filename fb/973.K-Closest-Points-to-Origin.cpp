// Time O(nlogk). Can do O(N) on average if using quick select
// Space O(k)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        
        for(auto point : points) {
            pq.push(point);
            if(pq.size() > K) {
                pq.pop();
            }
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};
