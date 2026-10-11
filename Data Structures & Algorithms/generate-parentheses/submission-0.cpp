class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string res;
        dfs(n, res, 0, 0);
        return ans;
    }

    void dfs(int n, string &res, int lp, int rp) {
        if( rp > lp || lp > n || rp > n) {
            return;
        }

        if (lp == rp && lp == n) {
            ans.push_back(res);
            return;
        }

        res.push_back('(');
        dfs(n, res, lp+1, rp);
        res.pop_back();
        res.push_back(')');
        dfs(n, res, lp, rp+1);
        res.pop_back();
    }
};
