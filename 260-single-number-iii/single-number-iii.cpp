class Solution {
public:
    // bool checkbit(int num, int i){
    //     if(num & (1 << i)) return true;
    //     return false;
    // }
    vector<int> singleNumber(vector<int>& nums) {
        // int n = nums.size();
        // int v = 0;
        // for(int i : nums){
        //     v = v^i;
        // }
        // int idx = 0;
        // for(int i = 0; i < 32; i++){
        //     if(checkbit(v, i)){
        //         idx = i;
        //         break;
        //     }
        // }
        // int set1 = 0;
        // int set2 = 0;
        // for(int i : nums){
        //     if(checkbit(i, idx)){
        //         set1 = set1^i;
        //     }
        //     else{
        //         set2 = set2^i;
        //     }
        // }
        // return {set1, set2};



        long long bitmask = 0;
        for(int i : nums){
            bitmask ^= i;
        }

        long long diff = bitmask & (-bitmask);

        int x = 0, y = 0;
        for(int i : nums){
            if((diff & i )!= 0){
                x ^= i;
            }
            else{
                y ^= i;
            }
        }
        return {x, y};
    }
};