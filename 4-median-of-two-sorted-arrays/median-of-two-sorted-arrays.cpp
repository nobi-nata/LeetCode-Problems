class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;

        int i = 0;
        int j = 0;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
            else{
                arr.push_back(nums2[j]);
                j++;
            }
        }
        while(i < nums1.size()){
            arr.push_back(nums1[i]);
            i++;
        }
        while(j < nums2.size()){
            arr.push_back(nums2[j]);
            j++;
        }
        int s = arr.size();
        if(s%2 == 1){
            return (double)arr[s/2];
        }
        return ((double)arr[s/2 - 1]+(double)arr[s/2])/2;
    }
};