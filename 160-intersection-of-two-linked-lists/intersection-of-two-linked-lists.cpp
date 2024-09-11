/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*curr1=headA;
        ListNode*curr2=headB;
        int c1=0;
        int c2=0;
        while(curr1!=NULL)
        {
            c1++;
            curr1=curr1->next;

        }
        while(curr2!=NULL)
        {
            c2++;
            curr2=curr2->next;
        }
        int length=abs(c1-c2);
        curr1=headA;
        curr2=headB;
        if(c1>c2)
        {
            while(length--){

            curr1=curr1->next;

            
        }


        }
        else{
            while(length--){

            curr2=curr2->next;
            }

        }
        while(curr1!=NULL || curr2!=NULL)
        {
            if(curr1==curr2)
            {
                return curr1;

            }
            curr1=curr1->next;
            curr2=curr2->next;
        }

        return NULL;
        
    }
};