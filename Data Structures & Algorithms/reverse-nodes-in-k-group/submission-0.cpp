class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // This tracks the tail of the PREVIOUS reversed group
        ListNode* prev_group_tail = dummy;
        
        while (true) {
            // 1. Probe ahead to find the k-th node
            ListNode* kth_node = prev_group_tail;
            for (int i = 0; i < k && kth_node != nullptr; i++) {
                kth_node = kth_node->next;
            }
            
            // If we didn't find k nodes, we are done!
            if (kth_node == nullptr) {
                break;
            }
            
            // 2. Prepare for reversal
            ListNode* next_group_head = kth_node->next;
            
            // The first node of our current group (will become the tail after reversal)
            ListNode* curr_group_head = prev_group_tail->next; 
            
            ListNode* curr = curr_group_head;
            // PRO-TRICK: Initialize prev to the NEXT group so the tail connects automatically!
            ListNode* prev = next_group_head; 
            
            // 3. Reverse exactly k nodes
            for (int i = 0; i < k; i++) {
                ListNode* next_node = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next_node;
            }
            
            // 4. Reconnect the previous group to our newly reversed group
            prev_group_tail->next = kth_node; // kth_node is the new head of this reversed group
            
            // 5. Shift our anchor forward for the next iteration
            prev_group_tail = curr_group_head; 
        }
        
        ListNode* new_head = dummy->next;
        delete dummy; // Clean up memory leak
        return new_head;
    }
};
