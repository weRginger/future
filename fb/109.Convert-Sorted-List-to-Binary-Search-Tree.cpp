// Time O(n)
// Space O(logn)
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        ListNode* node = head;
        int count = 0;
        while (node) {
            node = node->next;
            count++;
        }
        cur = head;
        return sortedListToBST(0, count - 1);
    }
    
private:
    ListNode* cur;
    
    TreeNode* sortedListToBST(int lo, int hi) {
        if (lo > hi) return nullptr;
        int mid = lo + (hi - lo)/ 2;
        TreeNode* left = sortedListToBST(lo, mid - 1);
        TreeNode* root = new TreeNode(cur->val);
        cur = cur->next;
        TreeNode* right = sortedListToBST(mid + 1, hi);
        root->left = left;
        root->right = right;
        return root;
    }
};
