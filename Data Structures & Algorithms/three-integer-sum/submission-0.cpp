class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
 
        for (int i = 0; i < nums.size(); i++) {

            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            int target = -(nums[i]);

            int start = i + 1;
            int end = nums.size() - 1;

            while (start < end) {
                if (start == i) {
                    start++;
                    continue;
                }
                if (end == i) {
                    end--;
                    continue;
                }

                if (nums[start] + nums[end] > target) {
                    end--;
                    continue;
                }

                if (nums[start] + nums[end] < target) {
                    start++;
                    continue;
                }

                if (nums[start] + nums[end] == target) {
                    res.push_back({nums[i], nums[start], nums[end]});

                    start++;
                    end--;

                    while (start < end && nums[start] == nums[start-1]){
                        start++;
                    }

                    while (start < end && nums[end] == nums[end+1]){
                       end--;
                    }
                }
            }
        }

        return res;
    }
};
