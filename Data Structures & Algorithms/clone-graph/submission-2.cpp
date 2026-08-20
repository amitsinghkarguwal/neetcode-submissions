class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> oldToNew;
        queue<Node*> q;

        // Clone the starting node and push the ORIGINAL node to the queue
        oldToNew[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            // Pop the current original node from the front of the queue
            Node* curr = q.front();
            q.pop();

            // Iterate through all neighbors of the current original node
            for (Node* neighbor : curr->neighbors) {
                // If the neighbor hasn't been cloned yet
                if (oldToNew.find(neighbor) == oldToNew.end()) {
                    // Clone it and add to map
                    oldToNew[neighbor] = new Node(neighbor->val);
                    // Push the ORIGINAL neighbor to the queue for future processing
                    q.push(neighbor);
                }
                
                // Link the cloned neighbor to the cloned current node
                oldToNew[curr]->neighbors.push_back(oldToNew[neighbor]);
            }
        }

        return oldToNew[node];
    }
};