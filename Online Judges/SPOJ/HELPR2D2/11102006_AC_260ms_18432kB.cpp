#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int tr[4 * N + 4], sv[N + 4];

void up(int p, int s, int e, int x, int v)
{
    if (s == e && s == x)
    {
        tr[p] = v;
        return ;
    }
    int m = (s + e) / 2;
    int l = p * 2;
    int r = l + 1;
    if (m >= x) up(l, s, m, x, v);
    else up(r, m + 1, e, x, v);
    tr[p] = max(tr[l], tr[r]);
}
int qr(int p, int s, int e, int k)
{
    if (s == e) return s;
    int m = (s + e) / 2;
    int l = p * 2;
    int r = l + 1;
    if (tr[l] >= k) return qr(l, s, m, k);
    else return qr(r, m + 1, e, k);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int k, n, r, c, ts;
    string s;
    cin >> ts;
    while (ts--)
    {
        memset(tr, 0, sizeof tr);
        cin >> k;
        cin >> n;
        for (int i = 1; i <= N; i++)
        {
            up(1, 1, N, i, k);
            sv[i] = k;
        }
        for (int i = 1; i <= n;)
        {
            cin >> s;
            if (s == "b")
            {
                cin >> r >> c;
                while (r--)
                {
                    int ii = qr(1, 1, N, c);
                    sv[ii] -= c;
                    up(1, 1, N, ii, sv[ii]);
                    i++;
                }
            }
            else
            {
                c = atoi(s.c_str());
                int ii = qr(1, 1, N, c);
                sv[ii] -= c;
                up(1, 1, N, ii, sv[ii]);
                i++;
            }
        }
        int Ansx = 0, Ansy = 0;
        for (int i = 1; i <= N; i++)
        {
            if (sv[i] >= k) break;
            Ansx++;
            Ansy += sv[i];
        }
        cout << Ansx << " " << Ansy << endl;
    }
    return 0;
}
