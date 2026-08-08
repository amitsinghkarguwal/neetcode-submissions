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



class Solution {
public:
    // Hash map to store the mapping from original node to cloned node
    unordered_map<Node*, Node*> oldToNew;

    Node* cloneGraph(Node* node) {
        // Base case: if the input node is null
        if (!node) return nullptr;

        // If the node has already been cloned, return the clone
        if (oldToNew.find(node) != oldToNew.end()) {
            return oldToNew[node];
        }

        // Create a copy of the current node
        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        // Recursively clone all neighbors
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }

        return copy;
    }
};