class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int low = 0;
        int high = nums.size() - 1;

        int mid;
        int min_val = nums[0];

        while (low <= high) {
            if (nums[low] <= nums[high]) {
                min_val = min(min_val, nums[low]);
                break;
            }
            mid = low + ((high-low)/2);

            min_val = min(min_val, nums[mid]); 
            if (nums[mid] >= nums[low]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return min_val;
    }
};
