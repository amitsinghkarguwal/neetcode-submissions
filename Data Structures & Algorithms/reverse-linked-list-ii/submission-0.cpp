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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev_left = dummy;
        for (int i = 0; i < left - 1; i++) {
            prev_left = prev_left->next;
        }
        
        ListNode* curr = prev_left->next; // 'curr' is the first node to be reversed
        ListNode* prev = nullptr;
        ListNode* next_node = nullptr;
        
        for (int i = 0; i < right - left + 1; i++) {
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        
        prev_left->next->next = curr;
        
        // Connect the node before the reversal zone to the new HEAD of our reversed section.
        prev_left->next = prev;
        
        ListNode* new_head = dummy->next;
        delete dummy;
        
        return new_head;
    }
};