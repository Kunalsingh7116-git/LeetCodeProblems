class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prevStockPrice = prices[0];
        int profit = 0;
        for(int i = 1;i < prices.size();i++){
            if(prices[i] > prevStockPrice) {
                profit = max(profit,prices[i]- prevStockPrice);
            }
            else {
                prevStockPrice = prices[i];
            }
        }
        return profit;
    }
};