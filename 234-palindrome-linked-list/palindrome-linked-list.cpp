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
    ListNode* front;
    bool check(ListNode* Node){
        if (Node!=NULL) {
            if (!check(Node->next)) return 0;
        //    cout<<"("<<Node->val<<","<<front->val<<")";
            if (Node->val!=front->val) return 0;
            front=front->next;
        }
        return 1;
    }
    bool isPalindrome(ListNode* head) {
        front=head;
        return check(head);
    }
};