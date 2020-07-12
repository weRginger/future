// source https://zxi.mytechroad.com/blog/tree/leetcode-437-path-sum-iii/
// Time O(n)
// Space O(H)
// Same idea to LC 560. Subarray Sum Equals K
class Solution {
public:
  int pathSum(TreeNode* root, int sum) {
    ans_ = 0;
    sums_ = {{0, 1}};
    pathSum(root, 0, sum);
    return ans_;
  }
private:
  int ans_;
  unordered_map<int, int> sums_;
  
  void pathSum(TreeNode* root, int cur, int sum) {
    if (!root) return;
    cur += root->val;
    ans_ += sums_[cur - sum];
    ++sums_[cur];
    pathSum(root->left, cur, sum);
    pathSum(root->right, cur, sum);
    --sums_[cur];
  }
};

// Time O(n^2)
// Space O(n)
class Solution {
public:
  int pathSum(TreeNode* root, int sum) {
    if (!root) return 0;
    return numberOfPaths(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
  }
private:
  int numberOfPaths(TreeNode* root, int left) {
    if (!root) return 0;    
    left -= root->val;
    return (left == 0 ? 1 : 0) + numberOfPaths(root->left, left) + numberOfPaths(root->right, left);
  }
};
