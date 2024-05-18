// Time O(n)
// Space O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy{0};
        dummy.next = head;
        ListNode* p = &dummy, *q = &dummy;
        while (n--) p = p->next;
        while (p->next != nullptr) {
            p = p->next, q = q->next;
        }
        q->next = q->next->next;
        return dummy.next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
