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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        ListNode* head3;
        ListNode dummy(0);
        head3=&dummy;
        ListNode* itr3=head3;


        while(list1!=NULL && list2!=NULL){
            ListNode* newNode=new ListNode;
            newNode->next=NULL;

            if(list1->val <= list2->val){
                newNode->val = list1->val;
                list1=list1->next;
            }
            else {
                newNode->val = list2->val;
                list2=list2->next;
            }
            
            itr3->next=newNode;
            itr3=itr3->next;

        }

        if(list1!=NULL){
            itr3->next=list1;
        }
        if(list2!=NULL){
            itr3->next=list2;
        }

        return head3->next;
        
    }
};