// Time O(E+log(E/V))
// Space O(E+V)
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(const auto& t : tickets)
            trips_[t[0]].push_back(t[1]);
        
        for(auto& pair : trips_) {
            auto& dests = pair.second;
            sort(dests.begin(), dests.end());
        }
        
        const string kStart = "JFK";
        
        visit(kStart);
        
        return vector<string>(route_.crbegin(), route_.crend());
    }
private:
    // src -> {dst1, dest2, ..., destn}
    unordered_map<string, deque<string>> trips_;    
    // ans (reversed)
    vector<string> route_;
    
    void visit(const string& src) {
        auto& dests = trips_[src];
        while (!dests.empty()) {
            // Get the smallest dest
            const string dest = dests.front();
            // Remove the ticket
            dests.pop_front();
            // Visit dest
            visit(dest);
        }
        // Add current node to the route
        route_.push_back(src);
    }
};
