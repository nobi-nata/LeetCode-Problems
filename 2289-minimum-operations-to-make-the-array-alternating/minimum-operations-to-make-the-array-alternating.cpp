class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // unordered_map<int,int>even,odd;
        // odd[0]=0,even[0]=0;
        // int oddlen=0,evenlen=0,n=nums.size(),firstodd=0,secondodd=0,firsteven=0,secondeven=0,firstoddcount=0,secondoddcount=0,firstevencount=0,secondevencount=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(i%2)
        //     {
        //         oddlen++;
        //         odd[nums[i]]++;
        //     }
        //     else
        //     {
        //         evenlen++;
        //         even[nums[i]]++;
        //     }
        // }
        // for(auto i:odd)
        // {
        //     if(i.second>=firstoddcount)
        //     {
        //         secondoddcount=firstoddcount;
        //         secondodd=firstodd;
        //         firstodd=i.first;
        //         firstoddcount=i.second;
        //     }
        //     else if(i.second>secondoddcount)
        //     {
        //          secondoddcount=i.second;
        //          secondodd=i.first;
        //     }
        // }
        //  for(auto i:even)
        // {
        //     if(i.second>=firstevencount)
        //     {
        //         secondevencount=firstevencount;
        //         secondeven=firsteven;
        //         firsteven=i.first;
        //         firstevencount=i.second;
        //     }
        //     else if(i.second>secondevencount)
        //     {
        //          secondevencount=i.second;
        //          secondeven=i.first;
        //     }
        // }
        // int operations=1e9;
        // if(firsteven!=firstodd) operations=evenlen-firstevencount+oddlen-firstoddcount;
        // return min(operations,min(evenlen-secondevencount+oddlen-firstoddcount,evenlen-firstevencount+oddlen-secondoddcount));

        int mark[100001][2] = {}, i, j, k, res = 0;
        for (i = 0; i < nums.size(); i++)
            mark[nums[i]][i & 1]++;
        for (i = 1, j = k = 0; i <= 100000; i++)
            res = max(res, max(mark[i][0] + k, mark[i][1] + j)), j = max(j, mark[i][0]), k = max(k, mark[i][1]);
        return nums.size() - res;
    }
};