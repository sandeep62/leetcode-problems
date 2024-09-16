/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL; 
        // creating a new node of linkedlist wo=ith the value curr;
        Node*curr=head;
        while(curr!=NULL){
           Node*next=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=next;
            curr=next;

        }
        // connecting the random nodes accordingly 
        curr=head;
        while(curr!=NULL){
            curr->next->random=(curr->random!=NULL) ? curr->random->next : NULL;
            curr=curr->next->next;

        }
        //traverse through the linkedlist and delete the alternate one
        Node*newNode=head->next;
        Node*copyNode=newNode;
        curr=head;
        while(curr!=NULL){
            curr->next=curr->next->next;
            if(copyNode->next!=NULL){
                copyNode->next=copyNode->next->next;
            }
            curr=curr->next;
            copyNode=copyNode->next;
        }

        return newNode;

        
    }
};