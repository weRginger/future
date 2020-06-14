// One pass
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* first = &dummy;
        ListNode* second = &dummy;
        // Advances first pointer so that the gap between first and second is n nodes apart
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }
        // Move first to the end, maintaining the gap
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy.next;
    }
};

// Two pass
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* first = head;
        int l = 0;
        while(first != NULL) {
            l++;
            first = first->next;
        }
        first = &dummy;
        for(int i = 0; i < l - n; i++) {
            first = first->next;
        }
        first->next = first->next->next;
        return dummy.next;
    }
};
