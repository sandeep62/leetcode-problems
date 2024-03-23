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
 #pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    ListNode* left;
    int n=0;
    void transverse(ListNode* right, int cnt){
        if (!right) return;
        n=max(n, cnt+1);
        transverse(right->next, cnt+1);
   
        if (cnt<= n/2) return;//most tricky part

        // cout<<"("<<left->val<<","<<right->val<< ")cnt="<<cnt<<endl;
        ListNode* Next = left->next;
        left->next = right;
        right->next = Next;
        left = Next;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

    //    n=1;
    //    for(ListNode* cur=head; cur; cur=cur->next) n++;
            
        left=head;
        transverse(head->next, 2);
        left->next=NULL;
    }
};