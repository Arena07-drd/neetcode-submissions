class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());

        while (stones.size() > 1) {
            pop_heap(stones.begin(), stones.end());
            int x = stones.back();
            stones.pop_back();
            pop_heap(stones.begin(), stones.end());
            int y = stones.back();
            stones.pop_back();
            if (x == y) {
                continue;
            } else {
                stones.push_back(abs(x-y));
                push_heap(stones.begin(), stones.end());
            }
        }

        if (stones.size()) {
            pop_heap(stones.begin(), stones.end());
            return stones.back();
        } else {
            return 0;
        }
    }
};
