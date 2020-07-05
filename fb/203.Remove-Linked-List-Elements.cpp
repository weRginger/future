// Time O(n)
// Space O(1)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode sentinel;
        sentinel.next = head;

        ListNode *prev = &sentinel, *curr = head, *toDelete = nullptr;
        while (curr != nullptr) {
          if (curr->val == val) {
            prev->next = curr->next;
            toDelete = curr;
          } else prev = curr;

          curr = curr->next;

          if (toDelete != nullptr) {
            delete toDelete;
            toDelete = nullptr;
          }
        }

        return sentinel.next;
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
