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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){
            head=NULL;
            return head;
        }

        if(head->next->next==NULL){
            if(n==1){
                head->next=NULL;
                return head;
            }
            else{
                head=head->next;
                return head;
            }
        }
        

        ListNode* ahead=head;
        int count=n-1;
        while(count!=0){
            ahead=ahead->next;
            count--;
        }
        ListNode* back=NULL;
        ListNode* behind=head;
        while(ahead->next!=NULL){
            ahead=ahead->next;
            back=behind;
            behind=behind->next;
        }

        if(behind==head) return head->next;
        else{
            back->next=back->next->next;
        }
        return head;
    }
};