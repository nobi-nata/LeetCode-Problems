class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if(k >= n-1) return *max_element(arr.begin(), arr.end());

        unordered_map<int,int> mp;

        for(int i = 1; i < n; i++){
            if(arr[i] > arr[0]){
                swap(arr[i], arr[0]); 
            }
            mp[arr[0]]++;
            if(mp[arr[0]] >= k) return arr[0];
        }

        return arr[0];
    }
};