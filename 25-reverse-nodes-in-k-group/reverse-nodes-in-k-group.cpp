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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*curr=head, *next=NULL,*prev=NULL;
        int count=0;
        // to check atleast k nodes remains in the linkedlist 
        while(curr!=NULL && count<k)
        {
            curr=curr->next;
            count++;
        }
        if(count<k)
        {
            return head;
        }
        curr=head;
        count=0;
        while(curr!=NULL && count<k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(next!=NULL)
        {
            ListNode*rest_head=reverseKGroup(next,k);
            head->next=rest_head;
        }
        return prev;
        
    }
};