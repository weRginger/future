/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // the leftmost *non-leaf* node in each level for level-wise iteration.
        TreeLinkNode* head = root;
        // cusor to traverse each level.
        TreeLinkNode* current = nullptr;
        // the node who's next is not its sibling and will be set in next
        // iteration of |current|.
        TreeLinkNode* pending = nullptr;

        while(head) {
            current = head;
            head = nullptr;
            while (current) {
                if (pending) {
                    pending->next = current->left ? current->left : current->right;
                }

                if (TreeLinkNode* left = current->left) {
                    left->next = current->right;
                    pending = left;
                    if (!head) {
                        head = left->left || left->right ? left : nullptr;
                    }
                }
                if (TreeLinkNode* right = current->right) {
                    pending = right;
                    if (!head) {
                        head = right->left || right->right ? right : nullptr;
                    }
                }
                current = current->next;
            }
            pending = nullptr;
        }
    }
};