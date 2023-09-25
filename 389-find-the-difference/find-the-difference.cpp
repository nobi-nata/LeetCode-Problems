class Solution {
public:
    char findTheDifference(string s, string t) {
        // unordered_map<char,  int> mp;
        
        // for(auto i : t){
        //     mp[i]++;
        // }
        // for(auto i : s){
        //     mp[i]--;
        // }
        // for(auto i : mp){
        //     if(i.second == 1) return i.first;
        // }
        // return ' ';


        // char result = 0;
        // for (char c : s) {
        //     result ^= c; 
        // }
        
        // for (char c : t) {
        //     result ^= c; 
        // }
        
        // return result;


        char result = 0;
        for (char c : s + t) {
            result ^= c;
        }
        return result;
    }
};