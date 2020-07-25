// Time O(n)
// Space O(n)
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "#";
        string res;
        queue<Node*> q{{root}};
        while (!q.empty()) {
            Node *t = q.front(); q.pop();
            res += to_string(t->val) + " " + to_string(t->children.size()) + " ";
            for (Node *child : t->children) {
                q.push(child);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream iss(data);
        queue<Node*> qNode;
        queue<int> qSize;
        string val = "", size = "";
        iss >> val;
        if (val == "#") return NULL;
        iss >> size;
        Node *res = new Node(stoi(val)), *cur = res;
        qNode.push(cur);
        qSize.push(stoi(size));
        while (!qNode.empty()) {
            Node *t = qNode.front(); qNode.pop();
            int len = qSize.front(); qSize.pop();
            for (int i = 0; i < len; ++i) {
                if (!(iss >> val)) break;
                if (!(iss >> size)) break;
                cur = new Node(stoi(val));
                qNode.push(cur);
                qSize.push(stoi(size));
                t->children.push_back(cur);
            }
        }
        return res;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
