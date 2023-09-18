// class Solution {
// public:
//     vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
//         int n = arr.size();

//         priority_queue<pair<double, pair<int,int>> , vector<pair<double, pair<int,int>>>, greater<pair<double, pair<int,int>>> > pq;

//         for(int i = 0; i < n; i++){
//             for(int j = i+1; j < n; j++){
//                 pq.push({(double)arr[i]/arr[j], {arr[i], arr[j]}});
//             }
//         }

//         while(k > 1){
//             pq.pop();
//             k--;
//         }
//         int x = pq.top().second.first;
//         int y = pq.top().second.second;

//         return {x, y};
//     }
// };



class Solution {
public:
    int helper(float check, vector<int>& arr){
        int left = 0, right = arr.size();
        while(left<right){
            int mid = left + (right-left)/2;
            if(arr[mid]==check){
                return mid;
            }
            else if(arr[mid]>check){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return right;
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        float left = 0, right = 1;
        int n = arr.size();
        while(true){
            float mid = float((float(left)+float(right))/2);
            vector<int> bounds;
            for(int i=0;i<n;i++){
                bounds.emplace_back(helper(float(arr[i])/mid,arr));
            }
            int curr_sum = 0;
            for(auto b:bounds){
                if(b<n) curr_sum += (n-b);
            }
            // cout<<curr_sum<<endl;
            if(curr_sum > k){
                right = mid;
            }
            else if(curr_sum < k){
                left = mid;
            }
            else{
                int a = 0, b = 0;
                float mx = 0;
                for(int i=0;i<bounds.size();i++){
                    if(bounds[i]<n){
                        if(float(arr[i])/float(arr[bounds[i]]) > mx){
                            mx = float(arr[i])/float(arr[bounds[i]]);
                            a = arr[bounds[i]]; b = arr[i];
                        }
                    }
                }
                return {b,a};
            }
        }
        return {};
    }
};