// Time O(n)
// Space O(1)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy;
        // Find the m-1 th node
        for (int i = 0; i < m - 1; ++i) 
            p = p->next;
        ListNode* prev = p;
        ListNode* curr = p->next;
        ListNode* tail = curr;    
        // Reverse from m to n
        for (int i = m; i <= n; ++i) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }    
        //  Connect three parts
        p->next = prev;
        tail->next = curr;
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
