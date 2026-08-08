#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    // Custom comparator for the Min-Heap
    struct CompareNode {
        bool operator()(ListNode* const& p1, ListNode* const& p2) { 
            // Returning '>' flips it into a Min-Heap.
            return p1->val > p2->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-Heap storing ListNode pointers
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> minHeap;

        // 1. Push the head of every non-empty list into the heap
        for (ListNode* head : lists) {
            if (head != nullptr) {
                minHeap.push(head);
            }
        }

        // Dummy node to easily build the resulting merged list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // 2. Process the heap until it's empty
        while (!minHeap.empty()) {
            // Get the smallest node
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            // Attach it to our merged list
            tail->next = smallest;
            tail = tail->next; // Move the tail pointer forward

            // 3. If the node we just popped has a next node, push it into the heap
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }

        // Clean up the dummy node and return the true head of the merged list
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};