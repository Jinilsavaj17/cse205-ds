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

    int getLength(ListNode* head)
    {
        ListNode* temp = head;

        int cnt = 0;
        while(temp!=NULL)
        {
            cnt++;
            temp = temp -> next;
        }

        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head -> next == NULL)    return NULL;


        int len = getLength(head);

        int pos = len-n+1;

        //if it is at head

        if(pos == 1)
        {
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return head;
        }

        //middle node
        ListNode* prev = NULL;
        ListNode* curr = head;
        int cnt = 1;
        
        while(cnt!=pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

        return head;
    }
};