// class Solution {
// public:
//     static bool cmp(string a, string b){
//         if(a.size() == b.size()){
//             if(a < b) return true;
//             return false;
//         }
//         else if(a.size() < b.size()) return true;
//         return false;
//     }

//     string kthLargestNumber(vector<string>& nums, int k) {
//         sort(nums.begin(), nums.end(), cmp);
//         int n = nums.size();

//         return nums[n-k];
//     }
// };

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
         auto comp = [](string  &a, string &b) {
            if(a.size() == b.size()) {
                return a > b;
            }
            return a.size() > b.size();
        };

        priority_queue< string, vector<string>, decltype(comp) >pq(comp);
        for(auto &it : nums) {
            pq.push(it);
            if(pq.size() > k)pq.pop();
        }
        return pq.top();
    }
};