class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        auto comp = [](auto &a, auto &b) {return a.first > b.first;};
        // item.first is the value
        // item.second.first is row index
        // item.second.second is col index
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(comp)> q(comp);
        int range_start = 0, range_end = INT_MAX;
        int curr_max = INT_MIN;
        int i = 0;
        for (auto list : nums) {
          if (!list.empty()) {
            q.push(make_pair(list[0], make_pair(i, 0)));
          }
          curr_max = max(curr_max, list[0]);
          i++;
        }
        // When q.size() < nums.size(), it means one of the rows reaches the end.
        // So we can terminate the process.
        while (q.size() == nums.size()) {
          auto node = q.top();
          q.pop();
          if (range_end-range_start > curr_max-node.first) {
            range_start = node.first;
            range_end = curr_max;
          }
          node.second.second++;
          if (nums[node.second.first].size() > node.second.second) {
            node.first = nums[node.second.first][node.second.second];
            q.push(node);
            curr_max = max(curr_max, node.first);
          }
        }
        return vector<int> {range_start, range_end};    
    }
};
