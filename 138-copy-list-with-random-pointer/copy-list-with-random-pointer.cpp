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
        //1
        Node* iter = head;
        Node* front = head;
        while(iter != NULL){
            front = iter->next;
            Node* copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }

        //2
        iter = head;
        while(iter != NULL){
            if(iter->random != NULL){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }

        //3
        iter = head;
        Node* p = new Node(0);
        Node* c = p;
        while(iter != NULL){
            front = iter->next->next;
            c->next = iter->next;
            iter->next = front;
            c =c->next;
            iter = iter->next;
        }
        return p->next;
    }
};