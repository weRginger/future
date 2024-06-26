// Time O(n)
// Space O(H)
// same idea as recursive
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        Node *node=root;
        stack<Node*> st;

        Node *head=nullptr,*cur=nullptr,*prev=nullptr;
        while(!st.empty()||node) {
            if(node) {
                st.push(node);
                node=node->left;
            }
            else
            {
               if(!head) {
                   head=st.top();
                   prev=st.top();
                   cur=st.top();
               }
               else
               {
                   cur=st.top();
                   prev->right=cur;
                   cur->left=prev;
                   prev=cur;
               }
               node=st.top()->right;
               st.pop();
            }
        }
        if(cur) cur->right=head;
        if(head) head->left=cur;
        return head;
    }
};

// Time O(n)
// Space O(H)
class Solution {
  // the smallest (first) and the largest (last) nodes
  Node* first = NULL;
  Node* last = NULL;

  void helper(Node* node) {
    if (node) {
      // left
      helper(node->left);
      // node 
      if (last) {
        // link the previous node (last)
        // with the current one (node)
        last->right = node;
        node->left = last;
      }
      else {
        // keep the smallest node
        // to close DLL later on
        first = node;
      }
      last = node;
      // right
      helper(node->right);
    }
  }
public:
  Node* treeToDoublyList(Node* root) {
    if (!root) return NULL;

    helper(root);
    // close DLL
    last->right = first;
    first->left = last;
    return first;
  }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
