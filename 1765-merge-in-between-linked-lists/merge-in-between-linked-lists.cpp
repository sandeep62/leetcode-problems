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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*prevleft=nullptr,*right=nullptr,*head=list1;
        int id=0;
        while(head!=nullptr)
        {
            if(id==a-1){
                prevleft=head;

            }
            if(id==b+1){
                right=head;
            }
            head=head->next;
            id++;
        }
        ListNode*endlist2=list2;
        while(endlist2->next!=nullptr)
        {
            endlist2=endlist2->next;

        }
        prevleft->next=list2;
        endlist2->next=right;
        return list1;
    
        
    }
};