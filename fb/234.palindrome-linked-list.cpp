/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* reverse = slow->next;
        slow->next = NULL;
        ListNode* head2 = reverseList(reverse);
        while(head2) {
            if(head->val != head2->val)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        while(head) {
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
};