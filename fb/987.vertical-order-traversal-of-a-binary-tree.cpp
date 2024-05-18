// Time O(nlogn)
// Space O(n)
// Author: Huahua
class Solution {
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    if (!root) return {};
    int min_x = INT_MAX;
    int max_x = INT_MIN;
    map<pair<int, int>, multiset<int>> h; // {y, x} -> {vals}. NOTE: use map since it allows pair as key
    traverse(root, 0, 0, h, min_x, max_x);
    vector<vector<int>> ans(max_x - min_x + 1);
    for (const auto& m : h) {      
      int x = m.first.second - min_x;
      for(auto val : m.second) ans[x].push_back(val);
    }
    return ans;
  }
private:
  void traverse(TreeNode* root, int x, int y, 
                map<pair<int, int>, multiset<int>>& h,
                int& min_x,
                int& max_x) {
    if (!root) return;
    min_x = min(min_x, x);
    max_x = max(max_x, x);    
    h[{y, x}].insert(root->val); // {y, x} or {x, y} do not matter
    traverse(root->left, x - 1, y + 1, h, min_x, max_x);
    traverse(root->right, x + 1, y + 1, h, min_x, max_x);
  }
};
