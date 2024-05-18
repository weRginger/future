// Time O(n^3)
// Space O(n^2)
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_map<int, bool>> memo;
        return helper(stones, 0, 0, memo);
    }
    bool helper(const vector<int>& stones,
                int pos,
                int jump,
                unordered_map<int, unordered_map<int, bool>>& memo) {
        
        int n = stones.size();
        if (pos >= n - 1) return true;
        if (memo.count(pos) && memo[pos].count(jump)) return memo[pos][jump];
        for (int i = pos + 1; i < n; ++i) {
            int dist = stones[i] - stones[pos];
            if (dist < jump - 1) continue;
            if (dist > jump + 1) return memo[pos][jump] = false;
            if (helper(stones, i, dist, memo)) return memo[pos][jump] = true;
        }
        return memo[pos][jump] = false;
    }
};
