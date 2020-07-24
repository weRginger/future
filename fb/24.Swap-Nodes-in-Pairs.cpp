// Time O(n)
// Space O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0,head);
        ListNode* pre = &dummy;
        while(pre->next && pre->next->next){
            ListNode* first = pre->next;
            ListNode* second = first->next;
            ListNode* third = second->next;
            pre->next = second;
            first->next = third;
            second->next = first;
            // next pair
            pre = first;  // pre point to actually the second
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
