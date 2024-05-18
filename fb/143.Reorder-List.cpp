// Time O(n)
// Space O(1)
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;

        // find the middle of linked list [Problem 876]
        // in 1->2->3->4->5->6 find 4 
        ListNode* slow = head; 
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second part of the list [Problem 206]
        // convert 1->2->3->4->5->6 into 1->2->3 and 6->5->4
        // reverse the second half in-place
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* tmp;
        while (curr != NULL) {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        // merge two sorted linked lists [Problem 21]
        // merge 1->2->3 and 6->5->4 into 1->6->2->5->3->4
        ListNode* first = head;
        ListNode* second = prev;
        while (second->next != NULL) {
            tmp = first->next;
            first->next = second;
            first = tmp;

            tmp = second->next;
            second->next = first;
            second = tmp;
        }
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
