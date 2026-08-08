/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // If the list is empty or has only one node, no pairs exist
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* curr = head;
        
        while (curr != nullptr && curr->next != nullptr) {
            // 1. Calculate the GCD of the current pair
            int gcd_val = std::gcd(curr->val, curr->next->val);
            
            // 2. Create the new node
            ListNode* new_node = new ListNode(gcd_val);
            
            // 3. Stitch it into the list
            new_node->next = curr->next;
            curr->next = new_node;
            
            // 4. Safely advance the pointer past the newly inserted node
            curr = new_node->next;
        }
        
        return head;
    }
};