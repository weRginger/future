// Time O(n)
// Space O(n)
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;

        Node dummy(0, nullptr, head, nullptr);
        Node* curr = &dummy;
        Node* prev = &dummy;

        stack<Node*> stk;
        stk.push(head);

        while (!stk.empty()) {
            curr = stk.top(); 
            stk.pop();
            prev->next = curr;
            curr->prev = prev;

            if (curr->next) stk.push(curr->next);
            if (curr->child) {
                stk.push(curr->child);
                // don't forget to remove child pointers.
                curr->child = nullptr;
            }
            prev = curr;
        }
        
        // NOTE: detach the dummy node from the result
        dummy.next->prev = nullptr;
        
        return dummy.next;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
