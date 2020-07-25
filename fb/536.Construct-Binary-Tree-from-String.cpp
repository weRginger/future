// Time O(n)
// Space O(H)
class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.length() == 0) {
            return NULL;
        }
        int index = 0;
        return str2tree(s, index);
    }
private:
    TreeNode* str2tree(const string &s, int &index) {
        int sign = 1, value = 0;
        if (s[index] == '-') {
            sign = -1;
            ++index;
        }
        while (index < s.length() && isdigit(s[index])) {
            value = 10 * value + s[index++] - '0';
        }
        TreeNode *root = new TreeNode(sign * value);
        if (index < s.length() && s[index] == '(') {
            ++index;        // skip the '(' that start the left subtree
            root->left = str2tree(s, index);
            ++index;        // skip the ')' that end the left subtree
            if (index < s.length() && s[index] == '(') {
                ++index;    // skip the '(' that start the right subtree
                root->right = str2tree(s, index);
                ++index;    // skip the ')' that end the right subtree
            }
        }
        return root;
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
