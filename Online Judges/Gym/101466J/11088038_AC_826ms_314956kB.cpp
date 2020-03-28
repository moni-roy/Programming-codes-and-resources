#include <bits/stdc++.h>
using namespace std;
const int MX = 4e7;
const int MD = 3e7;
int n, m, q, a[MX], b, mp[MX];
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &a[i]);
        mp[a[i]]++;
    }
    for (int i = m + 1; i <= n; i++)
    {
        a[i] = (a[i - m] + a[i - m + 1]) % MD;
        mp[a[i]]++;
    }
    int id = 1;
    for (int i = 0; i <= MD; i++)
    {
        while (mp[i]--)
        {
            a[id++] = i;
        }
    }
    while (q--)
    {
        scanf("%d", &b);
        printf("%d\n", a[b]);
    }
    return 0;
}

