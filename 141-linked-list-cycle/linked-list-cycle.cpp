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
    bool hasCycle(ListNode *head) {
       ListNode* slow = head;
       ListNode* fast = head;
       if(head == NULL) return false;
       do{
           fast = fast->next;
           if(fast != NULL){
               fast = fast->next;
           }
           slow = slow->next;
       }while(fast != NULL && (fast != slow));
       if(fast == NULL) return false;
       return true;
    }
};