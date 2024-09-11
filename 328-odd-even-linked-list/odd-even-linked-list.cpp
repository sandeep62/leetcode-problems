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
    ListNode* oddEvenList(ListNode* head) {
        // Check if the list is empty or has only one node
        if (!head || !head->next) return head;

        ListNode* eS = NULL;  // Even start
        ListNode* eE = NULL;  // Even end
        ListNode* oS = NULL;  // Odd start
        ListNode* oE = NULL;  // Odd end
        int count = 1;        // Counter to distinguish odd and even positions

        for (ListNode* curr = head; curr != NULL; curr = curr->next) {
            if (count % 2 != 0) {  // Odd nodes
                if (oS == NULL) {
                    oS = curr;  // First odd node
                    oE = oS;
                } else {
                    oE->next = curr;  // Link odd nodes
                    oE = oE->next;
                }
            } else {  // Even nodes
                if (eS == NULL) {
                    eS = curr;  // First even node
                    eE = eS;
                } else {
                    eE->next = curr;  // Link even nodes
                    eE = eE->next;
                }
            }
            count++;
        }

        // Now connect the last odd node to the first even node
        oE->next = eS;

        // Make sure the last even node points to NULL
        eE->next = NULL;

        return oS;  // Head of the odd list
    }
};
