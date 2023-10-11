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
    ListNode* Mid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* mergedsortedlist(ListNode* l1, ListNode* l2){
        if(l1==NULL || l2==NULL) return (l1==NULL)? l2:l1;
        
        ListNode* ans=new ListNode(-1);
        ListNode* temp = ans;
        while(l1!=NULL & l2!=NULL){
            if(l1->val<=l2->val){
                temp->next=l1;
                temp=temp->next;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                temp=temp->next;
                l2=l2->next;
            }
        }
        if(l1!=NULL || l2!=NULL) temp->next= (l1!=NULL)? l1:l2;
        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head== NULL || head->next==NULL) return head;
        ListNode* mid= Mid(head);
        ListNode* newhead=mid->next;
        mid->next=NULL;

        ListNode* lefthalf = sortList(head);
        ListNode* righthalf= sortList(newhead);
        
        return mergedsortedlist(lefthalf,righthalf);
    }
};