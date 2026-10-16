class Solution {
public:

    vector<string> letterCombinations(string digits) {
        
        if (digits.empty()) return {};

        vector<string> characters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string res="";
        vector<string> ans;

        dfs(digits, res, ans, 0, characters);

        return ans;
        
    }

    void dfs(string digits, string &res, vector<string> &ans, int j, vector<string> characters) {
        if(j >= digits.size()) {
            ans.push_back(res);
            return;
        }

        int index = digits[j] - '2';
        for (int i=0; i < characters[index].size(); i++){
            res.push_back(characters[index][i]);
            dfs(digits, res, ans, j+1, characters);
            res.pop_back();
        }
    }
};
