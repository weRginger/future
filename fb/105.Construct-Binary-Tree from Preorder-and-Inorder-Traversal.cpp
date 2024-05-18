// Time O(n)
// Space O(n)
// code source: https://zxi.mytechroad.com/blog/tree/leetcode-105-construct-binary-tree-from-preorder-and-inorder-traversal/
// video source: great video to understand this Q but missed hashmap optimization. https://www.youtube.com/watch?v=S1wNG5hx-30
class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); i++)
      pos[inorder[i]] = i;
    return helper(preorder, inorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
  }
    
private:
    unordered_map<int, int> pos;
    
    TreeNode* helper(vector<int> &preorder, vector<int> &inorder,
                     int is, int ie, int ps, int pe) {
      if (is > ie || ps > pe) return NULL;
 
      int im = pos[preorder[ps]];
      int pm = ps + (im - is);
 
      auto root = new TreeNode(preorder[ps]);
      root->left  = helper(preorder, inorder, is, im - 1, ps + 1, pm);
      root->right = helper(preorder, inorder, im + 1, ie, pm + 1, pe);
      return root;
    };
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
