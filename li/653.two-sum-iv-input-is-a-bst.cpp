// Time: O(n)
// Space: O(log(n))
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) {
            return false;
        }

        stack<TreeNode*> leftSide;
        stack<TreeNode*> rightSide;

        // Find the greatest and smallest Node in the Tree first.
        TreeNode* tmp = root;
        while (tmp != NULL) {
            leftSide.push(tmp);
            tmp = tmp->left;
        }
        tmp = root;
        while (tmp != NULL) {
            rightSide.push(tmp);
            tmp = tmp->right;
        }

        // Then perform the same 2 pointer idea like we are facing a sorted list
        // However, in this case, we always try to traverse the tree to looking
        // for the next smaller or larger TreeNode. This is applicable since
        // this is a BST.
        TreeNode* left = leftSide.top();
        leftSide.pop();
        TreeNode* right = rightSide.top();
        rightSide.pop();

        while (left->val != right->val) {
            // If there is no redundant number in the Tree,
            // then left.val == right.val can indicates a thorough search is completed.
            int currSum = left->val + right->val;
            if (currSum == k) {
                return true;
            } else if (currSum < k) {
                if (left->right != NULL) {
                    left = left->right;
                    while (left != NULL) {
                        leftSide.push(left);
                        left = left->left;
                    }
                }
                left = leftSide.top();
                leftSide.pop();
            } else { // currSum > k
                if (right->left != NULL) {
                    right = right->left;
                    while (right != NULL) {
                        rightSide.push(right);
                        right = right->right;
                    }
                }
                right = rightSide.top();
                rightSide.pop();
            }
        }

        return false;
    }
};

// Time: O(n)
// Space: O(n)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        vector<int> v;
        helper(root, v);
        int l = 0, r = v.size() - 1;
        while(l < r) {
            if(v[l] + v[r] == k) {
                return true;
            }
            else if(v[l] + v[r] > k) {
                r--;
            }
            else {
                l++;
            }
        }
        return false;
    }
    void helper(TreeNode* root, vector<int>& v) {
        if(!root) {
            return;
        }
        helper(root->left, v);
        v.push_back(root->val);
        helper(root->right, v);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
