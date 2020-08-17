// Time O(n)
// Space O(n)
// http://zxi.mytechroad.com/blog/tree/leetcode-863-all-nodes-distance-k-in-binary-tree/
class Solution {
public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    buildGraph(nullptr, root);    
    vector<int> ans;
    unordered_set<TreeNode*> seen;    
    queue<TreeNode*> q;
    seen.insert(target);
    q.push(target);
    int k = 0;
    while (!q.empty() && k <= K) {
      int s = q.size();
      while (s--) {
        TreeNode* node = q.front(); q.pop();
        if (k == K) ans.push_back(node->val);    
        for (TreeNode* child : g[node]) {
          if (seen.count(child)) continue;
          q.push(child);
          seen.insert(child);
        }
      }
      ++k;
    }
    return ans;
  }
private:  
  unordered_map<TreeNode*, vector<TreeNode*>> g;
  
  void buildGraph(TreeNode* parent, TreeNode* child) {      
    if (parent) {
      g[parent].push_back(child);
      g[child].push_back(parent);
    }
    if (child->left) buildGraph(child, child->left);
    if (child->right) buildGraph(child, child->right);
  }
};
