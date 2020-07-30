// Time O(N1+N2)
// Space O(H1+H2)
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        while(root1) {
            s1.push(root1);
            root1 = root1->left;
        }
        while(root2) {
            s2.push(root2);
            root2 = root2->left;
        }
        vector<int> ans;
        while(!s1.empty() && !s2.empty()) {
            if(s1.top()->val <= s2.top()->val) {
                ans.push_back(s1.top()->val);
                pushS1();
            } else {
                ans.push_back(s2.top()->val);
                pushS2();
            }
        }
        while(!s1.empty()) {
            ans.push_back(s1.top()->val);
            pushS1();
        }
        while(!s2.empty()) {
            ans.push_back(s2.top()->val);
            pushS2();
        }
        return ans;
    }
private:
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    
    void pushS1() {
        TreeNode* root = s1.top();
        s1.pop();
        if(root->right) {
            root = root->right;
            while(root) {
                s1.push(root);
                root = root->left;
            }
        }
    }
    
    void pushS2() {
        TreeNode* root = s2.top();
        s2.pop();
        if(root->right) {
            root = root->right;
            while(root) {
                s2.push(root);
                root = root->left;
            }
        }
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
