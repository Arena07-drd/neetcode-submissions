class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;
        backtrack(s, 0, 0, res, ans);
        return ans;
    }

    void backtrack(string &s, int start, int end, vector<string> &res, vector<vector<string>> &ans) {

        if (end >= s.length()) {
            if (end == start) {
                ans.push_back(res);
            }

            return;
        }

        if (isValid(s, start, end)) {
            res.push_back(s.substr(start, end-start+1));
            backtrack(s, end+1, end+1, res, ans);
            res.pop_back();
        }

        backtrack(s, start, end+1, res, ans);

    }

    bool isValid(string s, int start, int end) {
        while(start < end) {
            if (s[start] != s[end]){
                return false;
            }
             start++;
            end--;
        }
        return true;
    }
};
