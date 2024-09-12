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
    ListNode* swapNodes(ListNode* head, int k) {
        int count=0;
        int s=1;
        ListNode*curr=head ,*start=NULL,*end=NULL;
        if(curr==NULL || curr->next==NULL)
        {
            return head;
        }
        // finding the length of the linkedlist
        while(curr!=NULL)
        {
            count++;
            curr=curr->next;
        }

        for(ListNode*curr=head;curr!=NULL;curr=curr->next)
        {
            if(s==k)
            {
                start=curr;


            }
            if(s==(count-k+1))
            {
                end=curr;
            }
            s++;
        }

        swap(start->val,end->val);
        
        return head;
        
    }
};