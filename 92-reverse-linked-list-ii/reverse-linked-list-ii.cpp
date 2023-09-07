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
    // ListNode* reverse(ListNode* head, int left, int right){

    // }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<ListNode*> st;
        ListNode* p = head;
        int i = 1;
        ListNode* s = head;
        if(left == right) return head;
        while(i < left){
            s = p;
            p = p->next;
            i++;
        }
        while(i <= right){
            st.push(p);
            p = p->next;
            i++;
        }
        auto temphead = st.top();
        while(!st.empty()){
            ListNode* it = st.top();
            st.pop();
            if(!st.empty())it->next = st.top();
            else it->next = p; 
        }
        if(left != 1 && s->next != NULL) s->next = temphead;
        if(left == 1) return temphead;
        return head;
    }
};