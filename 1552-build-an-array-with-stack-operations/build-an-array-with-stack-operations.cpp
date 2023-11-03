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



        vector<string> result;
        int current = 1; // The current number to be pushed.

        for (int i = 0; i < target.size(); i++) {
            while (current < target[i]) {
                // While the current number is less than the target number,
                // push the current number and generate the "Push" operation.
                result.push_back("Push");
                result.push_back("Pop"); // After pushing, immediately pop.
                current++;
            }

            // The current number matches the target number, so push it.
            result.push_back("Push");

            current++; // Move to the next number to be pushed.
        }
        return result;
    }
};