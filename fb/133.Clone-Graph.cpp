// Time O(V+E)
// Space O(V)
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return node;
        }

        // Hash map to save the visited node and it's respective clone
        // as key and value respectively. This helps to avoid cycles.
        unordered_map<Node*, Node*> visited;

        // Put the first node in the queue
        queue<Node*> q;
        q.push(node);
        // Clone the node and put it in the visited dictionary.
        visited[node] = new Node(node->val);

        // Start BFS traversal
        while (!q.empty()) {
            // Pop a node say "n" from the from the front of the queue.
            Node* n = q.front();
            q.pop();
            // Iterate through all the neighbors of the node "n"
            for (const auto& neighbor: n->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    // Clone the neighbor and put in the visited, if not present already
                    visited[neighbor] = new Node(neighbor->val);
                    // Add the newly encountered node to the queue.
                    q.push(neighbor);
                }
                // Add the clone of the neighbor to the neighbors of the clone node "n".
                (visited[n]->neighbors).push_back(visited[neighbor]);
            }
        }

        // Return the clone of the node from visited.
        return visited[node];
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
