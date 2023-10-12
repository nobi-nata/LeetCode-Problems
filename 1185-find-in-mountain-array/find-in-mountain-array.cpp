/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    void bs1(int s, int e, int target, MountainArray &mountainArr, int &ans){
        while(s <= e){
            int mid = s + (e-s)/2;
            int midEle = mountainArr.get(mid);
            if(midEle == target){
                ans = min(ans, mid);
                e = mid-1;
            }
            if(midEle < target){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
    }
    void bs(int s, int e, int target, MountainArray &mountainArr, int &ans){
        while(s <= e){
            int mid = s + (e-s)/2;
            int midEle = mountainArr.get(mid);
            if(midEle == target){
                ans = min(ans, mid);
                e = mid-1;
            }
            if(midEle < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int i = 0;
        int n = mountainArr.length();
        int j = n-1;
        int s;

        while(i <= j){
            int mid = i + (j-i)/2;
            int midEle = mountainArr.get(mid);
            
            if(mid == 0 || mountainArr.get(mid - 1) < midEle){
                if(mid == n-1 || midEle > mountainArr.get(mid+1)){
                    s = mid;
                    break;
                }
                else{
                    i = mid+1;
                }
            }
            else{
                j = mid-1;
            }
        }

        // cout << s;
        int ans = INT_MAX;
        bs(0, s, target, mountainArr, ans);
        if(ans != INT_MAX) return ans;
        cout << ans;
        bs1(s+1, n-1, target, mountainArr, ans);
        if(ans != INT_MAX) return ans;
        return -1;
    }
};