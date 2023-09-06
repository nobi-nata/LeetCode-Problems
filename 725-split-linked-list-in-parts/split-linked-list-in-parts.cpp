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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        // Create a vector of ListNode pointers to store the k parts.
        vector<ListNode*> parts(k, nullptr);

        // Calculate the length of the linked list.
        int len = 0;
        for (ListNode* node = root; node; node = node->next)
            len++;

        // Calculate the minimum guaranteed part size (n) and the number of extra nodes (r).
        int n = len / k, r = len % k;

        // Initialize pointers to traverse the linked list.
        ListNode* node = root, *prev = nullptr;

        // Loop through each part.
        for (int i = 0; node && i < k; i++, r--) {
            // Store the current node as the start of the current part.
            parts[i] = node;
            // Traverse n + 1 nodes if there are remaining extra nodes (r > 0).
            // Otherwise, traverse only n nodes.
            for (int j = 0; j < n + (r > 0); j++) {
                prev = node;
                node = node->next;
            }
            // Disconnect the current part from the rest of the list by setting prev->next to nullptr.
            prev->next = nullptr;
        }

        // Return the array of k parts.
        return parts;
    }
};

// class Solution {
// public:
//     vector<ListNode*> splitListToParts(ListNode* head, int k) {
//         ListNode *p = head;
//         int n = 0;

//         while(p != NULL){
//             n++;
//             p = p->next;
//         }
//         vector<ListNode*> ans(k, NULL);
//         int t , r, c = 1;
//         cout << n << endl;
//         if(k >= n){
//             t = 1;
//             r = 1;
//             c = 1;
//         }else{
//             if(n%k) r = n%k;
//             r += n/k;
//             t = n/k;
//             while((r - t) > 1){
//                 r--;
//                 c++;
//             }
//         }
//         cout << r << ' ' << t;
//         p = head;
//         ListNode* q = NULL;
        
//         int i;
//         for(i = 0; i < c; i++){
//             int y = r;
//             ans[i] = p;
//             while(y > 0 && p != NULL){
//                 q = p;
//                 p = p->next;
//                 y--;
//             }
//             // if(q) cout << q-> val;
//             if(q != NULL) q->next = NULL;
//         }
//         for(; i < k; i++){
//             int z = t;
//             // if(p) cout << p->val;
//             ans[i] = p;
//             while(z > 0 && p != NULL){
//                 q = p;
//                 p = p->next;
//                 z--;
//             }
//             if(q != NULL) q->next = NULL;
//         }
//         return ans;
//     }
// };