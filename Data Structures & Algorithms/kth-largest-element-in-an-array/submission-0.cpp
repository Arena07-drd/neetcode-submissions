class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;

        for(int n: nums) {
            maxHeap.push(n);
        }

        if (k == 1) {
            return maxHeap.top();
        }

        for (int i=0; i < k-1; i++) {
            maxHeap.pop();
        }

        return maxHeap.top();
    }
};
