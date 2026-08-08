#include <unordered_map>

using namespace std;

// Definition for a Node (provided by LeetCode).
/*
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Hash map mapping original nodes to their corresponding copied nodes
        unordered_map<Node*, Node*> oldToNew;

        // 1st Pass: Create all the nodes and populate the map
        Node* curr = head;
        while (curr != nullptr) {
            oldToNew[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // 2nd Pass: Assign 'next' and 'random' pointers
        curr = head;
        while (curr != nullptr) {

            oldToNew[curr]->next = oldToNew[curr->next];
            oldToNew[curr]->random = oldToNew[curr->random];
            
            curr = curr->next;
        }

        // Return the copied head node
        return oldToNew[head];
    }
};