class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int max = 0;
        for (int i=prices.size()-1; i>=0; i--) {
            if (prices[i]>max) max=prices[i];
            if (max-prices[i]>profit) profit=max-prices[i];
        }
        return profit;
    }
};