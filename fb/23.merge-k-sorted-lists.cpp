// Time O(n*logk), where is n is size of each list and k is size of lists
// Space O(1)
class Solution {
private:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* head = &dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                head->next = l1;
                head = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                head = l2;
                l2 = l2->next;
            }
        }
        if(l1)
            head->next = l1;
        else
            head->next = l2;
        return dummy.next;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        int size = lists.size();
        while(size > 1) {
            for(int i = 0; i < size / 2; i++) {
                lists[i] = merge2Lists(lists[i], lists[size - 1 - i]);
            }
            size = (size + 1) / 2;
        }
        return lists[0];
    }
};

// Time O(n*logk), where is n is size of each list and k is size of lists
// Space O(k)
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto comp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(comp)>  q(comp);
        for(auto l : lists) {
            if(l)  q.push(l);
        }
        if(q.empty())  return NULL;

        ListNode* result = q.top();
        q.pop();
        if(result->next) q.push(result->next);
        ListNode* tail = result;
        while(!q.empty()) {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if(tail->next) q.push(tail->next);
        }
        return result;
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
