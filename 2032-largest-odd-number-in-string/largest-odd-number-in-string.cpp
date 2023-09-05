class Solution {
public:
    string largestOddNumber(string num) {
        deque<int> d;
        string ans;
        for(auto i : num){
            d.push_back(i-'0');
        }
        while(!d.empty()){
            if(d.back()%2){
                break;
            }
            d.pop_back();
        }

        while(!d.empty()){
            ans += (d.front()+'0');
            d.pop_front();
        }
        return ans;
    }
};