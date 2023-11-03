class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        // int i = 0;
        // vector<string> ans;
        // int ele = target[target.size()-1];
        // for(int num = 1; num <= n; num++){
        //     ans.push_back("Push");
        //     if(i < target.size() && target[i] != num){
        //         ans.push_back("Pop");
        //     }
        //     else{
        //         i++;
        //     }
        //     if(ele == num) break;
            
        // }
        // return ans;



        // vector<string> result;
        // int current = 1; // The current number to be pushed.

        // for (int i = 0; i < target.size(); i++) {
        //     while (current < target[i]) {
        //         // While the current number is less than the target number,
        //         // push the current number and generate the "Push" operation.
        //         result.push_back("Push");
        //         result.push_back("Pop"); // After pushing, immediately pop.
        //         current++;
        //     }

        //     // The current number matches the target number, so push it.
        //     result.push_back("Push");

        //     current++; // Move to the next number to be pushed.
        // }
        // return result;



         vector<string> operations;
        int targetIndex = 0; // Pointer for target array
        int currentNumber = 1; // Pointer for numbers 1 to n

        while (targetIndex < target.size()) {
            if (target[targetIndex] == currentNumber) {
                // If the current number in the target array matches the current number 1 to n
                // Push "Push" operation and move both pointers
                operations.push_back("Push");
                targetIndex++;
            } else {
                // If the numbers don't match, push "Push" followed by "Pop" operation
                // and only move the current number pointer
                operations.push_back("Push");
                operations.push_back("Pop");
            }
            currentNumber++;
        }

        return operations;
    }
};