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
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;

        ListNode *itr=head, *itr2=head->next;
        while(itr2!=NULL && itr2->next!=NULL && itr!=itr2){
            itr=itr->next;
            itr2=itr2->next->next;
        }

        if(itr==itr2) return true;
        else return false;
        
    }
};
