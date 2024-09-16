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
        unordered_map<Node*,Node*>hm;
        Node*curr=head;
        // creating the new node into the hash table 
        while(curr!=NULL){
            hm[curr]=new Node(curr->val);
            curr=curr->next;
        }
        // traverse through the original linkedlist 
        curr=head;
        while(curr!=NULL){
           hm[curr]->next = hm[curr->next]; 
            hm[curr]->random = hm[curr->random];
            curr = curr->next;
        }
        return hm[head];


        
    }
};