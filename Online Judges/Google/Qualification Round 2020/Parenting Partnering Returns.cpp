#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ts, cs = 0, n;
    vector<pair<int, pair<int, int>>> a;
    cin >> ts;
    while (ts--)
    {
        a.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            a.push_back({x, {y, i}});
        }
        sort(a.begin(), a.end());
        string Ans(n, 'm');
        int c = 0, j = 0;
        int flag = 0;
        for (auto x : a)
        {
            if (x.first >= c)
            {
                Ans[x.second.second] = 'C';
                c = x.second.first;
            }
            else if (x.first >= j)
            {
                Ans[x.second.second] = 'J';
                j = x.second.first;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        cout << "Case #" << ++cs << ": ";
        if (flag)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << Ans << endl;
    }
}
// 4
// 3
// 360 480
// 420 540
// 600 660
// 3
// 0 1440
// 1 3
// 2 4
// 5
// 99 150
// 1 100
// 100 301
// 2 5
// 150 250
// 2
// 0 720
// 720 1440