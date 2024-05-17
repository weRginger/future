// Time O(nlogn)
// Space O(n)
class Solution {
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    if (!root) return {};
    
    int min_x = INT_MAX;
    int max_x = INT_MIN;
<<<<<<< HEAD
    
    map<pair<int, int>, set<int>, decltype(comp)> h(comp); // {x, y} -> {vals}
=======
    map<pair<int, int>, multiset<int>> h; // {y, x} -> {vals}. NOTE: use map since it allows pair as key
>>>>>>> da86ef2 (Update 987.vertical-order-traversal-of-a-binary-tree.cpp)
    traverse(root, 0, 0, h, min_x, max_x);
    
    vector<vector<int>> ans(max_x - min_x + 1);
    for (const auto& m : h) {      
<<<<<<< HEAD
      int x = m.first.first - min_x;
      ans[x].insert(end(ans[x]), begin(m.second), end(m.second));
=======
      int x = m.first.second - min_x;
      for(auto n :m.second) ans[x].push_back(n);
>>>>>>> f375abb (Update 987.vertical-order-traversal-of-a-binary-tree.cpp)
    }
    
    return ans;
  }
 
private:
  static constexpr auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.first != b.first ? a.first < b.first : a.second < b.second;
  };
  
  void traverse(TreeNode* root, int x, int y, 
                map<pair<int, int>, set<int>, decltype(comp)>& h,
                int& min_x,
                int& max_x) {
    if (!root) return;
    min_x = min(min_x, x);
    max_x = max(max_x, x);    
    h[{x, y}].insert(root->val);
    traverse(root->left, x - 1, y + 1, h, min_x, max_x);
    traverse(root->right, x + 1, y + 1, h, min_x, max_x);
  }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
