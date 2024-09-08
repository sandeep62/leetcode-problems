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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode*curr=head;
        int L=0;
        // finding the length of the linkedlist 
        while(curr)
        {
            L++;

            curr=curr->next;
        }
        int eackBucketNodes= L/k;
        int remainder=L%k;
        vector<ListNode*>result(k,NULL);
        curr=head;
        ListNode*prev=NULL;
        for(int i=0;i<k;i++)
        {
            result[i]=curr;
            for(int count=0;count<eackBucketNodes + (remainder>0 ?1:0 );count++)
            {
                prev=curr;
                curr=curr->next;
            }
            if(prev!=NULL){
                prev->next=NULL;


            }
            remainder--;


        }
        return result;
        
    }
};