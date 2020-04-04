class Solution
{
public:
    int countLargestGroup(int n)
    {
        int a[40], mx = 0;
        for (int i = 0; i < 40; i++)
            a[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            int k = i;
            int t = 0;
            while (k)
            {
                t += k % 10;
                k /= 10;
            }
            a[t]++;
            mx = max(a[t], mx);
        }
        int Ans = 0;
        for (int i = 0; i < 40; i++)
            if (mx == a[i])
                Ans++;
        return Ans;
    }
};