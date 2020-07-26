// Time O(n)
// Space O(1)
// see LC solution for details https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/solution/
class Solution {
private:
    Node* prev = nullptr;
    Node* leftmost = nullptr;
    
    void processChild(Node* childNode) {
         
        // If the "prev" pointer is alread set i.e. if we
        // already found atleast one node on the next level,
        // setup its next pointer
        if (this->prev) {
            this->prev->next = childNode;
                    
        } else {
                
            // Else it means this child node is the first node
            // we have encountered on the next level, so, we
            // set the leftmost pointer
            this->leftmost = childNode;
        }    
                
        this->prev = childNode; 
    }
public:  
    Node* connect(Node* root) {
        
        if (!root) {
            return root;
        }
        
        // The root node is the only node on the first level
        // and hence its the leftmost node for that level
        this->leftmost = root;
        
        // Variable to keep track of leading node on the "current" level
        Node* curr = leftmost;
        
        // We have no idea about the structure of the tree,
        // so, we keep going until we do find the last level.
        // the nodes on the last level won't have any children
        while (this->leftmost) {
            
            // "prev" tracks the latest node on the "next" level
            // while "curr" tracks the latest node on the current
            // level.
            this->prev = nullptr;
            curr = this->leftmost;
            
            // We reset this so that we can re-assign it to the leftmost
            // node of the next level. Also, if there isn't one, this
            // would help break us out of the outermost loop.
            this->leftmost = nullptr;
            
            // Iterate on the nodes in the current level using
            // the next pointers already established.
            while (curr) {
                
                // Process both the children and update the prev
                // and leftmost pointers as necessary.
                if (curr->left) processChild(curr->left);
                if (curr->right) processChild(curr->right);
                
                // Move onto the next node.
                curr = curr->next;
            }
        }
                
        return root ;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
