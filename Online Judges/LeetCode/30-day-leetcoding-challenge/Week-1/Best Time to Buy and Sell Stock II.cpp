class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;
        int buy = prices[0];
        int sell = prices[0];
        int profit = 0;
        for (int index = 1; index < prices.size(); index++)
        {
            if (prices[index - 1] > prices[index])
            {
                profit += sell - buy;
                buy = prices[index];
                sell = buy;
            }
            else
            {
                sell = prices[index];
            }
        }
        profit += sell - buy;
        return profit;
    }
};