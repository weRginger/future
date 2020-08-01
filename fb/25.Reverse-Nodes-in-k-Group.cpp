// Time O(n)
// Space O(1)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode dummy(0);
        dummy.next = head;
        int len = 1;
        while (head = head->next) len++;
        ListNode* pre = &dummy;    
        for (int l = 0; l + k <= len; l += k) {
            ListNode* cur = pre->next;
            ListNode* nxt = cur->next;
            for (int i = 1; i < k; ++i) {
                cur->next = nxt->next;
                nxt->next = pre->next;
                pre->next = nxt;
                nxt = cur->next;
            }
            pre = cur;
        }
        return dummy.next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
