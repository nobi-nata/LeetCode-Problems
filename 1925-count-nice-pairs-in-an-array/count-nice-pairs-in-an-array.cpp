// class Solution {
// public:
//     int countNicePairs(vector<int>& nums) {
//         vector<int> rev;

//         for(int i = 0; i < nums.size(); i++){
//             int num = nums[i];
//             string s = to_string(num);
//             reverse(s.begin(), s.end());
//             rev.push_back(stoi(s));
//         }
//         int ans = 0;
//         for(int i = 0; i < nums.size(); i++){
//             for(int j = i+1; j < nums.size(); j++){
//                 if((nums[i] + rev[j]) == (nums[j] + rev[i])) ans++;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int reverse(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }

    int countNicePairs(std::vector<int>& nums) {
        const int mod = 1000000007;

        int len = nums.size();
        for (int i = 0; i < len; ++i)
            nums[i] = nums[i] - reverse(nums[i]);

        std::sort(nums.begin(), nums.end());

        long res = 0;
        for (int i = 0; i < len - 1; ++i) {
            long cont = 1;
            while (i < len - 1 && nums[i] == nums[i + 1]) {
                cont++;
                i++;
            }
            res = (res % mod + (cont * (cont - 1)) / 2) % mod;
        }

        return static_cast<int>(res % mod);
    }
};