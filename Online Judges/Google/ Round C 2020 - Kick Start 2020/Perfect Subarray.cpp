// Accepted for small dataset
#include <bits/stdc++.h>
using namespace std;

int Ans = 0;
map<int, int> mp;
int ts, cs = 0, n, a[100010], sum[100010];

int main()
{
    for (int i = 0; i < 3262; i++)
        mp[i * i] = 1;
    cin >> ts;
    while (ts--)
    {
        memset(sum, 0, sizeof sum);
        Ans = 0;
        cin >> n;
        sum[0] = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum[i + 1] = sum[i] + a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                if (mp.find(sum[j] - sum[i - 1]) != mp.end())
                    Ans++;
            }
        }
        cout << "Case #" << ++cs << ": " << Ans << endl;
    }
}