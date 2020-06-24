class Solution
{
public:
    int dp[100010] = {0};
    int numTrees(int n)
    {
        if (n <= 1)
            return 1;
        if (dp[n] != 0)
            return dp[n];
        int ret = 0;
        for (int i = 0; i < n; i++)
            ret += numTrees(i) * numTrees(n - i - 1);
        return dp[n] = ret;
    }
};