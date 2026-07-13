class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int currBuy = prices[0];
        int maxProfit = 0;

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < currBuy) currBuy = prices[i];
            
            maxProfit = max(maxProfit, prices[i] - currBuy);
        }

        return maxProfit;
    }
};
