class Solution {
public:
    vector<string> ans;

    void recur(string digits, vector<string> key, int id, string temp){
        if(id == digits.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < key[digits[id]-'0'].size(); i++){
            recur(digits, key, id+1, temp + key[digits[id]-'0'][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> key = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        if(digits.size() == 0) return {};        
        recur(digits, key, 0, "");
        return ans;
    }
};