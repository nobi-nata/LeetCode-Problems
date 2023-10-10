class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        cout << num;
        int firstdef = -1;
        for(int i = num.size()-2; i >= 0; i--){
            if(num[i] < num[i+1]){
                firstdef = i;
                break;
            }
        }
        cout << firstdef;
        if(firstdef == -1) return -1;
        cout << num[firstdef];
        int nextLarge = -1;
        int nextMax = INT_MAX;
        for(int i = firstdef+1; i < num.size(); i++){
            if(num[firstdef] < num[i] && nextMax > num[i]){
                nextMax = num[i];
                nextLarge = i;
            }
        }
        if(nextLarge == -1) return -1;
        swap(num[firstdef], num[nextLarge]);
        sort(num.begin() + firstdef + 1, num.end());

        long ans = stol(num);

        if(ans > INT_MAX) return -1;
        return (int)ans;
    }
};