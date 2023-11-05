class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        // int n = arr.size();
        // if(k >= n-1) return *max_element(arr.begin(), arr.end());

        // unordered_map<int,int> mp;

        // for(int i = 1; i < n; i++){
        //     if(arr[i] > arr[0]){
        //         swap(arr[i], arr[0]); 
        //     }
        //     mp[arr[0]]++;
        //     if(mp[arr[0]] >= k) return arr[0];
        // }

        // return arr[0];


        //  if (k == 1) {
        //     return std::max(arr[0], arr[1]);
        // }
        // if (k >= arr.size()) {
        //     return *std::max_element(arr.begin(), arr.end());
        // }

        int current_winner = arr[0];
        int consecutive_wins = 0;

        for (int i = 1; i < arr.size(); ++i) {
            if (current_winner > arr[i]) {
                consecutive_wins++;
            } else {
                current_winner = arr[i];
                consecutive_wins = 1;
            }

            if (consecutive_wins == k) {
                return current_winner;
            }
        }

        return current_winner;
    }
};