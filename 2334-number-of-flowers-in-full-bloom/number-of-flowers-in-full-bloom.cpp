class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // sort(flowers.begin(), flowers.end());
        // vector<int> ans;
        // for(int i = 0; i < people.size(); i++){
        //     int cnt = 0;
        //     for(int j = 0; j < flowers.size(); j++){
        //         if(people[i] >= flowers[j][0] && people[i] <= flowers[j][1]) cnt++;
        //         else if(people[i] < flowers[j][0]) break;
        //     }
        //     ans.push_back(cnt);
        // }
        // return ans;

        vector<int> start, end;
        for (auto& t : flowers)
            start.push_back(t[0]), end.push_back(t[1]);
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        vector<int> res;
        for (int t : people) {
            int started = upper_bound(start.begin(), start.end(), t) - start.begin();
            int ended = lower_bound(end.begin(), end.end(), t) - end.begin();
            res.push_back(started - ended);
        }
        return res;
    }
};