class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        int cost[101][101];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cost[i][j] = 1e8;
            }
        }
        cost[0][src] = 0;
        for (int i = 1; i <= k + 1; i++)
        {
            cost[i][src] = 0;
            for (auto flight : flights)
            {
                cost[i][flight[1]] = min(cost[i][flight[1]], cost[i - 1][flight[0]] + flight[2]);
            }
        }
        return cost[k + 1][dst] >= 1e8 ? -1 : cost[k + 1][dst];
    }
};