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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head; // Handle case where list is empty or has only one node

        ListNode* dummy = new ListNode(0);  // Create a dummy node to handle head removal cases
        dummy->next = head;
        ListNode* prev = dummy;  // Keep track of the node before the current duplicates
        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) {
            if (curr->val == curr->next->val) {
                // Move through all duplicates
                while (curr->next != NULL && curr->val == curr->next->val) {
                    ListNode* temp = curr;
                    curr = curr->next; // Move to next duplicate node
                    delete temp; // Delete the duplicate node
                }
                // Delete the last duplicate node
                ListNode* temp = curr;
                curr = curr->next;
                delete temp;

                // Skip all the duplicate nodes by connecting the prev node to curr
                prev->next = curr;
            } else {
                // If no duplicate, move prev forward
                prev = curr;
                curr = curr->next;
            }
        }

        // New head might have changed if duplicates were at the start
        ListNode* newHead = dummy->next;
        delete dummy;  // Clean up the dummy node
        return newHead;
    }
};
