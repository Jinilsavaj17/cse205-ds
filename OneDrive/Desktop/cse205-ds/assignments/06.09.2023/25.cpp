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

    bool hasKNodesRemaining(ListNode* head, int k) {
        int count = 0;
        while (head != NULL && count < k) {
            head = head->next;
            count++;
        }
        return count != k;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        //base case
        if(head==NULL || hasKNodesRemaining(head, k)) return head;

        //reverse first k nodes
        ListNode* curr=head;
        ListNode* nex=NULL;
        ListNode* pre=NULL;
        int count = 0;

        while(curr != NULL && count<k){
            nex=curr->next;
            curr->next=pre;
            pre=curr;
            curr=nex;
            count++;
        }

        //recursion
        if(nex!=NULL) head->next=reverseKGroup(nex,k);

        return pre;
    }
};