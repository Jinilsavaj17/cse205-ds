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
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        ListNode* temp = new ListNode(-1);

        ListNode* tempHead = temp;

        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                temp->next = l1;
                temp = temp->next;
                l1 = l1 -> next;
            }
            else
            {
                temp->next = l2;
                temp = temp->next;
                l2 = l2 -> next;
            }
        }

        if(l1 != NULL)    temp->next = l1;

        if(l2 != NULL)    temp->next = l2;
        
        return tempHead -> next;
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL)  return list2;

        if(list2 == NULL)  return list1;

        if(list1 == NULL && list2 == NULL)  return NULL;

        return merge(list1,list2);
    }
};