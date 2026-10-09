class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        dfs (candidates, 0, subset, res, target);
        return res;
    }

    void dfs(vector<int>&nums, int i, vector<int> &subset, vector<vector<int>> &res, int target) {

        if (target == 0) {
            res.push_back(subset);
            return;
        }

        if (target < 0 || i >= nums.size()) {
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, i+1, subset, res, target-nums[i]);
        subset.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        dfs(nums, i+1, subset, res, target);
    }
};
