class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int start = 0;
        int end = heights.size()-1;
        int max = 0;

        while(start < end) {
            int capacity = (end-start)*min(heights[start], heights[end]);
            if (capacity > max) {
                max = capacity;
            }

            if (heights[start] < heights[end]){
                start++;
            } else {
                end--;
            }
        }

        return max;
    }
};
