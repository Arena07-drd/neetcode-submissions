class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        long long sum = accumulate(piles.begin(), piles.end(), 0LL);
        int max_val = *max_element(piles.begin(), piles.end());

        int start = (sum + h - 1) / h;
        int end = max_val;
        
        while (start <= end) {
            int mid = start + ((end-start)/2);

            long long time = 0;
            for (int i = 0; i < piles.size(); i++) {
                time += (piles[i] + mid - 1)/mid;
            }

            if (time > h) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return start;
    }
};
