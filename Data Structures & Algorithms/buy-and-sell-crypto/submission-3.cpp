class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = INT_MAX;
        int max_profit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            max_profit = max(max_profit, price-minPrice);
        }

        return max_profit;
        
    }
};
