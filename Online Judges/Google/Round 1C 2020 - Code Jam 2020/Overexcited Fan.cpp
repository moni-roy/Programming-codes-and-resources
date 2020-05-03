#include <bits/stdc++.h>
using namespace std;


int main()
{
    int cs = 0, ts, x, y;
    string s;
    cin >> ts;
    while (ts--)
    {
        cin >> x >> y >> s;
        int t = 0;
        int flag = 0, Ans = 1e9;
        cout << "Case #" << ++cs << ": ";
       
        for (auto c : s)
        {
            if (c == 'E')
            {
                x += 1;
            }
            else if (c == 'N')
            {
                y += 1;
            }
            else if (c == 'W')
            {
                x -= 1;
            }
            else
                y -= 1;
            t++;
            if (abs(x)+abs(y) <= t)
            {
                Ans = min(Ans, t);
                flag = 1;
            }
        }
        if (!flag)
            cout << "IMPOSSIBLE" << endl;
        else
        {
            cout << Ans << endl;
        }
    }
    return 0;
}