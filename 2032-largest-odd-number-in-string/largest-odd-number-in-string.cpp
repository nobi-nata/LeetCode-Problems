class Solution {
public:
    string largestOddNumber(string num) {
        int e = num.size()-1;
        while(e >= 0){
            if((num[e]-'0')%2) break;
            e--;
        }
        return num.substr(0, e+1);
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