class Solution {
public:
    string largestOddNumber(string num) {
        int e = num.size()-1;
        string ans = "";
        while(e >= 0){
            if((num[e]-'0')%2) break;
            e--;
        }
        int i = 0;
        while(i <= e){
            ans += num[i];
            i++;
        }
        return ans;
    }
};

        // deque<int> d;
        // string ans;
        // for(auto i : num){
        //     d.push_back(i-'0');
        // }
        // while(!d.empty()){
        //     if(d.back()%2){
        //         break;
        //     }
        //     d.pop_back();
        // }

        // while(!d.empty()){
        //     ans += (d.front()+'0');
        //     d.pop_front();
        // }
        // return ans;