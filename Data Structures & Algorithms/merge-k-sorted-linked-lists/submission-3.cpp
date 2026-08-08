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

        priority_queue<ListNode*, vector<ListNode*>, CompareNode> minHeap;

        for (ListNode* head : lists) {
            if (head != nullptr) {
                minHeap.push(head);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next; // Move the tail pointer forward

            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};