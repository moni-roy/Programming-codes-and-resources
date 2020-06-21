#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, b, c, a;
    long long sum = 0;
    map<long long, long long> mp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sum += a;
        mp[a]++;
    }
    long long q;
    cin >> q;
    while (q--)
    {
        cin >> b >> c;
        if (mp.find(b) != mp.end())
        {
            sum -= (mp[b] * b);
            sum += (mp[b] * c);
            mp[c] += mp[b];
            mp[b] = 0;
        }
        cout << sum << endl;
    }
}