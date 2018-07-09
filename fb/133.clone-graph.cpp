/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    unordered_map<int,UndirectedGraphNode*> hash;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;
        if (hash.count(node->label))
            return hash[node->label];

        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        hash[node->label] = newNode;

        for(int i=0; i < node->neighbors.size(); i++) {
            newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return newNode;
    }
};