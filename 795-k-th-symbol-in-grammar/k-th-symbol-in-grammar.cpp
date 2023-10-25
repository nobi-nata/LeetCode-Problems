class Solution {
public:
    int kthGrammar(int n, int k) {
        // vector<int> prev;
        // prev.push_back(0);
        

        // for(int i = 1; i < n; i++){
        //     vector<int> curr;
        //     for(int j = 0; j < prev.size(); j++){
        //         if(prev[j] == 0){ 
        //             curr.push_back(0);
        //             curr.push_back(1);
        //         }
        //         else{ 
        //             curr.push_back(1);
        //             curr.push_back(0);
        //         }
        //     }
        //     prev = curr;
        // }
        // return prev[k-1];

        if (n == 1) return 0;
        int length = 1 << (n - 2);
        if (k <= length) return kthGrammar(n - 1, k);
        else return 1 - kthGrammar(n - 1, k - length);
    }
};