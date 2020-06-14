// Two pass
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* first = head;
        int l = 0;
        while(first != NULL) {
            l++;
            first = first->next;
        }
        first = dummy;
        for(int i = 0; i < l - n; i++) {
            first = first->next;
        }
        first->next = first->next->next;
        return dummy->next;
    }
};
