class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low = 0;
        int high = nums.size()-1;

        int mid;

        while (low <= high) {

            mid = low + ((high-low)/2);

            if(nums[mid] == target) {
                return mid; 
            }

            //left sorted half
            if (nums[low] <= nums[mid]) {

                if(target < nums[low] || target > nums[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }

            //right sorted half
            } else if (nums[high] >= nums[mid]) {

                if(target > nums[high] || target < nums[mid]){
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }

            }
        }

        return -1;
    }

};
