class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixMax(n, 0);
        vector<int> suffixMin(n, 0);

        prefixMax[0] = arr[0];
        suffixMin[n-1] = arr[n-1];
        for(int i = 1; i < n; i++){
            prefixMax[i] = max(prefixMax[i-1], arr[i]);
            suffixMin[n-i-1] = min(suffixMin[n-i], arr[n-i-1]);
        }
        int ans = 1;
        for(int i = 0; i < n-1; i++){
            if(prefixMax[i] <= suffixMin[i+1]){
                ans++;
            }
        }
        return ans;
    }
};