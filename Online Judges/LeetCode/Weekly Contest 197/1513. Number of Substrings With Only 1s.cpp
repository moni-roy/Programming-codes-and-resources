class Solution
{
public:
    long long MOD = 1e9 + 7;
    int numSub(string s)
    {
        long long cnt = 0, Ans = 0;
        for (int i = 0; s[i]; i++)
        {
            if (s[i] == '1')
            {
                cnt++;
            }
            else
            {
                Ans += ((cnt * (cnt + 1)) / 2) % MOD;
                Ans %= MOD;
                cnt = 0;
            }
        }
        Ans += ((cnt * (cnt + 1)) / 2) % MOD;
        Ans %= MOD;
        return Ans;
    }
};