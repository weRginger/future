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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val; // min heap; c++ default is max heap
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        for(auto list: lists) {
            if(list) pq.push(list);
        }
        ListNode dummy(0);
        ListNode* head = &dummy;
        while(!pq.empty()) {
            ListNode* cur = pq.top();
            pq.pop();
            head->next = cur;
            head = cur;
            if(cur->next) pq.push(cur->next);
        }
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
