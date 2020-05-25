class Solution
{
public:
    int x, y;
    vector<int> a, b;
    int dp[501][501];
    int go(int i, int j)
    {
        if (i >= x || j >= y)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = 0;
        int ret = go(i, j + 1);
        ret = max(ret, go(i + 1, j));
        for (int k = j; k < y; k++)
        {
            if (a[i] == b[k])
            {
                ret = max(ret, 1 + go(i + 1, k + 1));
            }
        }
        for (int k = i; k < x; k++)
        {
            if (a[k] == b[j])
            {
                ret = max(ret, 1 + go(k + 1, j + 1));
            }
        }
        return dp[i][j] = ret;
    }
    int maxUncrossedLines(vector<int> &A, vector<int> &B)
    {
        a = A;
        b = B;
        x = A.size();
        y = B.size();
        memset(dp, -1, sizeof dp);
        return go(0, 0);
    }
};