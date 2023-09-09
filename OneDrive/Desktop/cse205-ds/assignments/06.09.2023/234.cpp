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

    ListNode* reverseList(ListNode* head){
        ListNode* previous=NULL;
        ListNode* after=NULL;
        while(head!=NULL){
            after=head->next;
            head->next=previous;
            previous=head;
            head=after;
        }
        return previous;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;

        ListNode* slow=head;
        ListNode* fast=head;

        //finding mid term;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        slow=reverseList(slow);

        while(slow!=NULL){
            if(head->val!=slow->val) return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};