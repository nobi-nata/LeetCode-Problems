class Solution {
public:
     //utility function to check the frequency condition.
    bool satisfy(vector<int>& freq, int k){
        if(freq[0]>=k && freq[1]>=k && freq[2]>=k) return true;
        else return false;
    }

    //sliding window function.
    bool isValid(string s, int k, int ptr){
        vector<int> freq(3, 0);

        //prepare the first window
        for(int i=0; i<ptr; i++){
            freq[s[i]-'a']++;
        }
        if(satisfy(freq, k)) return true;

        //slide the window.
        int size = s.length();
        int left = ptr-1;
        int right = size-1;

        while(left>=0){
            freq[s[left]-'a']--;
            freq[s[right]-'a']++;
            if(satisfy(freq, k)) return true;
            left--;
            right--;
        }

        // if after sliding the whole window also true is not returned, so return false.
        return false;

    }

    int takeCharacters(string s, int k) {
        
        int start = 0;
        int end = s.length();
        int ans = INT_MAX;
        while(start<=end){
            int mid = start+(end-start)/2;

            if(isValid(s, k, mid)){
                ans = min(ans, mid);
                //move to left for smaller ans
                end = mid-1;
            }else{
                //ans not found so move to bigger index
                start = mid+1;
            }

        }

        if(ans==INT_MAX) ans = -1; //that means no validity found uptill now.

        return ans;

    }





    // bool check1(vector<int> &v,int &k){
    //     for(auto &i: v){
    //         if(i<k)return true;
    //     }
    //     return false;
    // }
    // int takeCharacters(string s, int k) {
    //     vector<int> v(3,0);
    //     for(auto &i: s){
    //         v[i-'a']++;
    //     }
    //     if(check1(v,k)){
    //         return -1;
    //     }
    //     int i = 0, j =0,n=s.length(),ans=0;
    //     while(i<n){
    //         v[s[i]-'a']--;
    //         while(check1(v,k)){
    //             v[s[j]-'a']++;
    //             j++;
    //         }
    //         ans = max(i-j+1,ans);
    //         // cout << ans << ' ';
    //         i++;
    //     }
    
    //     return s.length()-ans;
    // }
};