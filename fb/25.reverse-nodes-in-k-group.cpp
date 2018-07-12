// source: http://bangbingsyb.blogspot.com/2014/11/leetcode-reverse-nodes-in-k-group.html
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<2) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;
        while(p->next && p->next->next) {
            ListNode *prev = p->next, *cur = prev->next;
            int i=0;
            while(cur && i<k-1) {
                ListNode *temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
                i++;
            }

            if(i==k-1) {    // k nodes reversed
                ListNode *temp = p->next;
                p->next->next = cur;
                p->next = prev;
                p = temp;
            }
            else {  // less than k nodes reversed before reach end
                cur = prev->next;
                prev->next = NULL;
                while(cur != p->next) {
                    ListNode *temp = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = temp;
                }
                break;
            }
        }
        return dummy->next;
    }
};