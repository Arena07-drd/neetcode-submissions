class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size());
        vector<int> suffix(height.size());

        int end = height.size()-1;

         prefix[0] = height[0];
        for (int i = 1; i <= end; i++) {
            prefix[i] = max(prefix[i-1], height[i]);
        }

        suffix[end] = height[end];
        for (int i = end-1; i >= 0; i--) {
            suffix[i] = max(suffix[i+1], height[i]);
        }

        int area = 0;
        for (int i = 1; i < height.size()-1; i++) {
            area += min(prefix[i], suffix[i]) - height[i];
        }

        return area;
    }
};
