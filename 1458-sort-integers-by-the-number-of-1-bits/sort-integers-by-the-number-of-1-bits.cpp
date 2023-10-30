class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> vec;
        for(int i = 0 ; i < arr.size(); i++){
            pair<int,int> p;
            p.second = arr[i];
            int cnt = 0;
            while(arr[i]){
                if(arr[i]&1) cnt++;
                arr[i] >>= 1;
            }
            p.first = cnt;
            vec.push_back(p);
        }

        sort(vec.begin(), vec.end());
        vector<int> ans;
        for(auto i : vec){
            ans.push_back(i.second);
        }
        return ans;
    }
};