// Time O(n*(2^n))
// Space O(n)
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        // must sort OR will lead to error
        sort(candidates.begin(), candidates.end());
        vector<int> local;
        findCombination(res, 0, target, local, candidates);
        return res;
    }
    
private:
    void findCombination(vector<vector<int>>& res, const int order, const int target, vector<int>& local, const vector<int>& candidates) {
        if(target==0) {
            res.push_back(local);
            return;
        }
        for(int i = order; i<candidates.size(); i++) {
            if(candidates[i] > target) return;
            if(i != order && candidates[i] == candidates[i-1]) continue; // check duplicate combination
            local.push_back(candidates[i]);
            findCombination(res, i + 1, target - candidates[i] ,local, candidates); // recursive componenet
            local.pop_back();
        }
    }
};
