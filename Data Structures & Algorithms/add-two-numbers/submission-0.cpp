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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* head=new ListNode(0);
        ListNode* itr3=head;

        while(l1!=NULL || l2!=NULL || carry){
            int result=carry;
            if(l1!=NULL) result=result+l1->val;
            if(l2!=NULL) result=result+l2->val;
            ListNode* newNode=new ListNode(result%10);
            
            itr3->next=newNode;
            carry=result/10;
            itr3=itr3->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        return head->next;
    }
};