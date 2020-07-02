class Solution
{
public:
    int arrangeCoins(int n)
    {
        long long int l = 0, r = n, Ans = 0;
        while (l <= r)
        {
            long long int m = l + (r - l) / 2;
            if (m * (m + 1) <= (long long)n * 2)
            {
                Ans = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        return Ans;
    }
};