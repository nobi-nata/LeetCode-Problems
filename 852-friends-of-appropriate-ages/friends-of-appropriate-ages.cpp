class Solution {
public:
    int bs(vector<int> nums, int s, int e, int age){
        while(s < e){
            int mid = s + (e-s)/2;
            if(nums[mid] > ((age/2)+7)){
                e = mid;
            }
            else{
                s = mid+1;
            }
        }
        return e;
    }

    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        sort(ages.begin(), ages.end());
        int ans = 0;
        
        for(int i = n-1; i >= 0; i--){
            int cnt = 0;
            
            cout << i << " ";
            
            // cout << y << " ";
            int x = bs(ages, 0, i, ages[i]);
            int y = i-x;

            while(i > 0 && ages[i] == ages[i-1]){
                cnt++;
                i--;
            }
            // cout << x << " ";
            ans +=(cnt+1)*y;
            // cout << ans << "*";

        }
        return ans;
    }
};