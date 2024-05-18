// Time O(n)
// Space O(n) - O(1) solution could be found in LC but need to modify input nodes
class Solution {
private:
    unordered_map<Node*, Node *> um;
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        Node* newHead = NULL, * newTail = NULL, * curr2;
        while(curr){
            if(!newHead){
                newHead = new Node(curr->val);
                newTail = newHead;
                um[curr] = newHead;
            }else{
                newTail->next = new Node(curr->val);
                newTail = newTail->next;
                um[curr] = newTail;
            }
            curr = curr->next;
        }
        curr = head;
        curr2 = newHead;
        while(curr){
            curr2->random = um[curr->random];
            curr = curr->next;
            curr2 = curr2->next;
        }
        return newHead;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
