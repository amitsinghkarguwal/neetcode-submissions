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

    ListNode* reverse(ListNode* head){

        ListNode* now=head;
        ListNode* front=now->next;
        now->next=NULL;

        while(front!=NULL){
            ListNode* temp=front->next;
            front->next=now;
            now=front;
            front=temp;
        }
        return now;
    }

    void reorderList(ListNode* head) {
        if (!head->next || !head->next->next) return;
        ListNode *fast=head->next, *slow=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *head2=reverse(slow->next);
        slow->next=NULL;
        ListNode *head1=head;

        while(head2){
            ListNode *temp1=head1->next;
            ListNode *temp2=head2->next;
            head1->next=head2;
            head2->next=temp1;
            head2=temp2;
            head1=temp1;
        }
    }
};