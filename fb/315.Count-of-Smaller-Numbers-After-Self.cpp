// BST or BIT
// Too hard, don't fully understand
// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-315-count-of-smaller-numbers-after-self/
struct BSTNode {
    int val;
    int count;
    int left_count;
    BSTNode* left;
    BSTNode* right;    
    BSTNode(int val): val(val), count(1), left_count(0), left{nullptr}, right{nullptr} {}
    ~BSTNode() { delete left; delete right; }
    int less_or_equal() const { return count + left_count; }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return {};
        std::reverse(nums.begin(), nums.end());
        std::unique_ptr<BSTNode> root(new BSTNode(nums[0]));
        vector<int> ans{0};
        for (int i = 1; i < nums.size(); ++i)
            ans.push_back(insert(root.get(), nums[i]));
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    // Returns the number of elements smaller than val under root.
    int insert(BSTNode* root, int val) {
        if (root->val == val) {
            ++root->count;
            return root->left_count;
        } else if (val < root->val) {
            ++root->left_count;
            if (root->left == nullptr) {
                root->left = new BSTNode(val);            
                return 0;
            } 
            return insert(root->left, val);
        } else  {
            if (root->right == nullptr) {
                root->right = new BSTNode(val);
                return root->less_or_equal();
            }
            return root->less_or_equal() + insert(root->right, val);
        }
    }
};
